% Variables to be set
p_swarm.is_active_migration = false;
p_swarm.is_active_goal = false;
p_swarm.is_active_arena = true;
p_swarm.is_active_spheres = true;
p_swarm.is_active_cyl = false;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Number of agents
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Max radius of influence - Metric distance
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

p_swarm.r = 15;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Max number of neighbors - Topological distance
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if ~isfield(p_swarm, 'max_neig')
    p_swarm.max_neig = 10;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Radius of collision -
% it is the radius of the sphere that approximates
% the drone. A collision is counted when two 
% spheres intersect.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

p_swarm.r_coll = 0.5;
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Arena parameters - Cubic arena
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% x,y,z positions of the walls
p_swarm.x_arena = [-100 100; % x wall
                   -100 100]; % y_wall
p_swarm.center_arena = sum(p_swarm.x_arena, 2) / 2;

% Parameter that defines the influence radius of the arena repulsion force
p_swarm.d_arena = 1.5;

% Constant of proportionality of the arena repulsion force
p_swarm.c_arena = .1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Spheric obstacles parameters
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

p_swarm.spheres = [0 10; 0 10; 5 10];

p_swarm.n_spheres = length(p_swarm.spheres(1, :));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reference values
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Inter-agent distance
if ~isfield(p_swarm, 'd_ref')
    p_swarm.d_ref = 25;
end

% Velocity direction
p_swarm.u_ref = [1 0 0]';

% Speed
if ~isfield(p_swarm, 'v_ref')
    p_swarm.v_ref = 6;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Velocity and acceleration bounds for the agents
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

p_swarm.max_a = 10;
p_swarm.max_v = 7;
