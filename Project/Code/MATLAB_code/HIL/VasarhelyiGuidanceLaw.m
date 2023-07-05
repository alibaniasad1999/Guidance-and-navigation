%%%%%%% Vasarhelyi Guidance Law %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function velocity_law = VasarhelyiGuidanceLaw(position, velocity, dt)
    % Variables to be set
is_active_migration = false;
is_active_goal = false;
is_active_arena = true;
is_active_spheres = true;
is_active_cyl = false;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Number of agents
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Max radius of influence - Metric distance
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

r = 15;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Max number of neighbors - Topological distance
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


max_neig = 10;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Radius of collision -
% it is the radius of the sphere that approximates
% the drone. A collision is counted when two 
% spheres intersect.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

r_coll = 0.5;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Arena parameters - Cubic arena
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% x,y,z positions of the walls
x_arena = [-100 100; % x wall
                   -100 100]; % y_wall
center_arena = zeros(2, 1);
center_arena = sum(x_arena, 2) / 2;

% Parameter that defines the influence radius of the arena repulsion force
d_arena = 0;
d_arena = 1.5;


% Constant of proportionality of the arena repulsion force
c_arena = .1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Spheric obstacles parameters
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

spheres = [0 10; 0 10; 5 10];

n_spheres = length(spheres(1, :));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reference values
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Inter-agent distance

    d_ref = 25;


% Velocity direction
u_ref = [1 0 0]';

% Speed

    v_ref = 6;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Velocity and acceleration bounds for the agents
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

max_a = 10;
max_v = 7;

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Vasarhelyi Paramteres
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Repulsion

% Repulsion range
r0_rep = d_ref; % radius of repulsion
% Repulsion gain
p_rep = 0.3;


%% Friction

% Stopping point offset of alignment
r0_fric = 85.3;
% Coefficient of velocity alignment
C_fric = 0.05;
% Velocity slack of alignement
v_fric = 0.63;
% Gain of braking curve
p_fric = 3.2;
% Acceleration of braking curve
a_fric = 4.16;


%% Obstacles and wall parameters

% Stopping point offset of walls
r0_shill = 0.1;
% Velocity of virtual shill agents
v_shill = 1.6;
% Gain of bracking curve for walls
p_shill = 0.55;
% Acceleration of braking curve for walls
a_shill = 3.02;  
    r_agent = r_coll;
    % position: 1 x 2N vector of the positions of all the agents
    agent_number = floor(length(position)/2);
    agent_position = reshape(position, 2, agent_number);
    agent_velocity = reshape(velocity, 2, agent_number);
    pos = agent_position;
    vel = agent_velocity;

    % Initialize variables
    nb_agents = agent_number;
    M = zeros(nb_agents, nb_agents);    % Neighborhood matrix
    dist_mat = zeros(nb_agents, nb_agents);    % Distance matrix
    vel_rep = zeros(2, nb_agents);      % Repulsion velocity
    vel_fric = zeros(2, nb_agents);     % Velocity matching velocity
    vel_wall = zeros(2, nb_agents);     % Arena repulsion velocity
    vel_obs = zeros(2, nb_agents);      % Obstacle repulsion velocity
    vel_command = zeros(2, nb_agents);  % Total commanded velocity
    
    nb_agent_collisions = 0; % Nb of collisions among agents
    nb_obs_collisions = 0; % Nb of collisions against obstacles
    min_dist_obs = 20;

    
    for agent = 1:nb_agents
        %% Find neighbors
        
        % Compute agent-agent distance matrix
        p_rel = pos - pos(:, agent);
        dist = sqrt(sum((p_rel.^2), 1));
        dist_mat(agent, :) = dist;

        % Define neighbours list
        neig_list = (1:nb_agents)';
        neig_list = neig_list(dist ~= 0);

        % Count collisions
        nb_agent_collisions = nb_agent_collisions + sum(dist < 2 * r_agent) - 1;

        % Initialize number of neighbours
        nb_neig = nb_agents - 1;

        % Constraint on neighborhood given by the euclidean distance
            neig_list = neig_list(dist(neig_list) < r);
            nb_neig = length(neig_list);



        % Adjacency matrix (asymmetric in case of limited fov)
        M(agent, neig_list) = 1;
        
        %% Compute different contributions
        
        if nb_neig ~= 0
            v_rel = vel - vel(:, agent);
            v_rel_norm = sqrt(sum((v_rel.^2), 1));

            % Compute vel and pos unit vector between two agents
            p_rel_u = -p_rel ./ dist;
            v_rel_u = -v_rel ./ v_rel_norm;
            temp = neig_list';
            for agent2 = temp
                
                % Repulsion and attraction
                if dist(agent2) < r0_rep  % repulsion
                    vel_rep(:, agent) = vel_rep(:, agent) + ...
                        p_rep * (r0_rep - dist(agent2)) * p_rel_u(:, agent2);
                % else  % attraction
                %     vel_rep(:, agent) = vel_rep(:, agent) + ...
                %         p_rep * (dist(agent2) - r0_rep) *- p_rel_u(:, agent2);
                end

                % Velocity alignement
                v_fric_max = get_v_max(v_fric, dist(agent2) - r0_fric, a_fric, p_fric);

                if v_rel_norm(agent2) > v_fric_max
                    vel_fric(:, agent) = vel_fric(:, agent) + ...
                        C_fric * (v_rel_norm(agent2) - v_fric_max) * v_rel_u(:, agent2);
                end
            end
        end
        
        
        %% Wall and obstacle avoidance

        % Add arena repulsion effect
        if (is_active_arena == true)
            unit = eye(2);
            %On each axis we have the two repulsions
            for axis = 1:2
                %On each axis there is two forces (each side of the arena)
                for dir = 1:2
                    dist_ab = abs(pos(axis, agent) - x_arena(axis, dir));

                    %Compute velocity of wall shill agent toward center of the arena
                    v_wall_virtual = unit(:, axis) .* v_shill;

                    if dir == 2
                        v_wall_virtual = -v_wall_virtual;
                    end

                    %Compute relative velocity (Wall - Agent)
                    vel_ab = sqrt(sum((vel(:, agent) - v_wall_virtual).^2));

                    v_wall_max = get_v_max(0, dist_ab - r0_shill, a_shill, p_shill);

                    if vel_ab > v_wall_max
                        vel_wall(:, agent) = vel_wall(:, agent) + ...
                            (vel_ab - v_wall_max) * (v_wall_virtual - vel(:, agent)) ./ vel_ab;
                    end
                end
            end
        end

        % Compute spheric effect
        if (is_active_spheres == true)

            for obs = 1:n_spheres
                % Get obstacle center and radius
                c_obs = spheres(1:2, obs);
                r_obs = spheres(3, obs);

                % Compute distance agent(a)-obstacle(b)
                dist_ab = sqrt(sum((pos(:, agent) - c_obs).^2)) - r_obs;
                nb_obs_collisions = nb_obs_collisions + sum(dist_ab < r_agent);

                % Set the virtual speed of the obstacle direction out of
                % the obstacle
                v_obs_virtual = (pos(:, agent) - c_obs) / (dist_ab + r_obs) * v_shill;

                % Compute relative velocity agent-obstacle
                vel_ab = sqrt(sum((vel(:, agent) - v_obs_virtual).^2));

                if dist_ab < min_dist_obs
                    min_dist_obs = dist_ab;
                end

                v_obs_max = get_v_max(0, dist_ab - r0_shill, a_shill, p_shill);

                if vel_ab > v_obs_max
                    vel_obs(:, agent) = vel_obs(:, agent) + (vel_ab - v_obs_max) * (v_obs_virtual - vel(:, agent)) ./ vel_ab;
                end
            end
        end
        
        %% Sum agent-agent and obstacle contributions

        vel_command(:, agent) = vel_rep(:, agent) + vel_fric(:, agent) + vel_obs(:, agent) + vel_wall(:, agent);

        % Add self propulsion OR migration term
        v_norm = sqrt(sum((vel(:, agent).^2), 1));

        if is_active_migration == true% migration
            vel_command(:, agent) = vel_command(:, agent) + v_ref * u_ref;
        elseif is_active_goal == true
            x_goal_rel = x_goal - pos(:, agent);
            u_goal = x_goal_rel / norm(x_goal_rel);
            vel_command(:, agent) = vel_command(:, agent) + v_ref * u_goal;
        else
            % self-propulsion
            if v_norm > 0
                vel_command(:, agent) = vel_command(:, agent) + v_ref * vel(:, agent) / v_norm;
            end
        end
    end
    
    
    %% bound velocities and accelerations

    % Bound velocities and acceleration
    if ~isempty(max_v)
        vel_cmd_norm = sqrt(sum((vel_command.^2), 1));
        % v_norm = sqrt(sum((vel.^2), 1));

        idx_to_bound = (vel_cmd_norm > max_v);
        if sum(idx_to_bound) > 0
            vel_command(:, idx_to_bound) = max_v * ...
                vel_command(:, idx_to_bound) ./ repmat(vel_cmd_norm(idx_to_bound), 2, 1);
        end
    end
    if ~isempty(max_a)
        accel_cmd = (vel_command-vel)./dt;
        accel_cmd_norm = sqrt(sum(accel_cmd.^2, 1));
        idx_to_bound = ( accel_cmd_norm > max_a | accel_cmd_norm < - max_a);
        if sum(idx_to_bound) > 0
            vel_command(:, idx_to_bound) = vel(:, idx_to_bound) + ...
                dt*max_a * accel_cmd(:, idx_to_bound) ./ ...
                repmat(accel_cmd_norm(idx_to_bound), 2, 1);
        end
    end
    velocity_law = reshape(vel_command, 1, 2*nb_agents);

end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Calculate V fric max
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ v_fricmax ] = get_v_max(v_fric, r, a, p)

    if r < 0
        v_fricmax = 0;
    elseif r * p > 0 && r * p < a / p
        v_fricmax = r * p;
    else
        v_fricmax = sqrt(2 * a * r - a^2 / p^2);
    end

    if v_fricmax < v_fric
        v_fricmax = v_fric;
    end
end