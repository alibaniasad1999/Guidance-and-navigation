%% pso optimization %%
time_burn_1 = 73.8;
time_burn_2 = 60.8;
[pso_ans, ~] = particleswarm(@distance_calculator_east, 4, ...
    [-10, -10, -10, time_burn_1+1], [10, 10, 10, time_burn_1+1+time_burn_2+10]);
    q1 = pso_ans(1);
    q2 = pso_ans(2);
    q3 = pso_ans(3);
    t1 = pso_ans(4);
%% results %%
r = [0; 6378e3]; % initial position m
v = [0; 0]; % initial velocity km/s
y0 = [r; v]; % initial condition
% time %
tspan = [0 1000]; % time span
% stop condition %
options = odeset('Events', @stop_condition, 'RelTol', 1e-8, 'AbsTol', 1e-8);
% ode45 %
[t, y] = ode45(@(t,y) missle(t,y,q1, q2, q3, t1), tspan, y0, options);
cost = -acos(y(end, 1:2)*r/norm(y(end, 1:2))/norm(r));
cost = cost + 2*pi/24/3600*t(end);
fprintf('q1 = %f, q2 = %f, q3 = %f, t1 = %f, cost = %f\n', q1, q2, q3, t1, cost);

%% plot %%
set(gca, 'FontSize', 16)
plot(t, y(:, 1)...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../Figure/Q1/c');
if dir_state
    print('../../Figure/Q1/c/x', '-depsc');
else
    fprintf("Ooooooops\n")
end

set(gca, 'FontSize', 16)
plot(t, y(:, 2)...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../Figure/Q1/c');
if dir_state
    print('../../Figure/Q1/c/y', '-depsc');
else
    fprintf("Ooooooops\n")
end


set(gca, 'FontSize', 16)
plot(y(:, 1), y(:, 2)...
    , 'b', 'LineWidth', 2);
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../Figure/Q1/c');
if dir_state
    print('../../Figure/Q1/c/xy', '-depsc');
else
    fprintf("Ooooooops\n")
end


set(gca, 'FontSize', 16)
plot(t, sqrt(y(:, 1).^2 + y(:, 2).^2) - 6378e3...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Altitude(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../Figure/Q1/c');
if dir_state
    print('../../Figure/Q1/c/alt', '-depsc');
else
    fprintf("Ooooooops\n")
end


set(gca, 'FontSize', 16)
plot(t, atan2(y(:, 2), y(:, 1))...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Angle(rad)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../Figure/Q1/c');
if dir_state
    print('../../Figure/Q1/c/angle', '-depsc');
else
    fprintf("Ooooooops\n")
end

%%% ?????????????????? %%%
set(gca, 'FontSize', 16)
plot(atan2(y(:, 2), y(:, 1)),sqrt(y(:, 1).^2 + y(:, 2).^2) - 6378e3...
    , 'b', 'LineWidth', 2);
xlabel('Latitude', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Altitude', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../Figure/Q1/c');
if dir_state
    print('../../Figure/Q1/c/lat_vs_alt', '-depsc');
else
    fprintf("Ooooooops\n")
end

% earth and missle %
set(gca, 'FontSize', 16)
plot(6378e3*(cos(0:0.01:pi)), 6378e3*(sin(0:0.01:pi)),...
    'b', 'LineWidth', 2);
hold on
plot(y(:, 1), y(:, 2)...
    , 'r', 'LineWidth', 2);
legend('Earth', 'Missle');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
axis equal
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../Figure/Q1/c');
if dir_state
    print('../../Figure/Q1/c/xy_earth', '-depsc');
else
    fprintf("Ooooooops\n")
end



%% stop condition function %$
function [value, isterminal, direction] = stop_condition(~, y)
    r = y(1:2); % position
    value = (norm(r) - 6378e3)>=0; % stop condition
    isterminal = 1; % stop the integration
    direction = 0; % all direction
end
%% missle differential equation %%
function dydt = missle(t,y, q1, q2, q3, t1) % y = [x, y, vx, vy]
    r = y(1:2); % position
    v = y(3:4); % velocity
    G = 6.67408e-11; % gravitational constant
    M = 5.972e24; % mass of earth
    Gravity_acceleration = -G*M*r/norm(r)^3; % gravity acceleration
    Thrust = thrust_calculator(t); % thrust
    %%%%% need work for vaiable thrust vector %%%%%
    theta = theta_calculator(t, q1, q2, q3, t1);
    thrust_vec = thrust_vector_calculator(Thrust, theta, r); % thrust vector
    % drag %
    Drag = drag_calculator(t, y); % drag
    % mass %
    m = mass_calculator(t); % mass
    % differential equation %
    dydt = [v; (thrust_vec + Drag)/m + Gravity_acceleration];
end

% thrust calculation $
function T = thrust_calculator(t)
    m_stage_1 = 33820; % kg
    propellant_mass_fraction_1 = 0.88;
    propellant_mass_1 = m_stage_1 * propellant_mass_fraction_1;
    time_burn_1 = 73.8; % seconds
    propellant_mass_rate_1 = propellant_mass_1/time_burn_1;
    Isp_1 = 262; % seconds
    % second stage %
    m_stage_2 = 5780; % kg
    propellant_mass_fraction_2 = 0.85;
    propellant_mass_2 = m_stage_2 * propellant_mass_fraction_2;
    time_burn_2 = 60.8; % seconds
    propellant_mass_rate_2 = propellant_mass_2/time_burn_2;
    Isp_2 = 270; % seconds
    time_burn_2 = 60.8; % seconds
    if t < time_burn_1
        T = Isp_1 * propellant_mass_rate_1 * 9.81;
    elseif t < time_burn_1 + time_burn_2
        T = Isp_2 * propellant_mass_rate_2 * 9.81;
    else
        T = 0;
    end
end

% trust vector calculation %
function T = thrust_vector_calculator(trust, gamma, r)
    t_r = trust*sin(gamma);
    t_theta = trust*cos(gamma);
    % polar to cartesian %
    theta = atan2(r(2), r(1));
    % rotate matrix from polar to cartesian %
    T = [cos(theta) -sin(theta); sin(theta) cos(theta)]*[t_r; t_theta];
end

% drag calculation %
function D = drag_calculator(t, y)
    r = y(1:2)/1000; % position meter to kilometer
    h = norm(r) - 6378; % altitude
    % density %
    if h < 0
        rho = 1.225;
    elseif h < 11
        rho = 1.225*exp(-h/6.5);
    elseif h < 25
        rho = 0.3639*exp(-h/6.5);
    elseif h < 47
        rho = 0.08803*exp(-h/6.5);
    elseif h < 53
        rho = 0.01322*exp(-h/6.5);
    elseif h < 79
        rho = 0.00143*exp(-h/6.5);
    elseif h < 90
        rho = 0.00086*exp(-h/6.5);
    else
        rho = 0;
    end
    % velocity %
    v = y(3:4); % velocity
    % surface area %
    time_burn_1 = 73.8; % seconds
    surface_1 = 2.55;
    surface_2 = 1.23;
    if t < time_burn_1
        surface = surface_1;
    else
        surface = surface_2;
    end
    % drag %
    C_d = 0.2;
    D = -0.5*rho*norm(v)*v*surface*C_d;
end

% mass calculation %
function m = mass_calculator(t)
    m_total = 40600; % kg
    m_stage_1 = 33820; % kg
    propellant_mass_fraction_1 = 0.88;
    propellant_mass_1 = m_stage_1 * propellant_mass_fraction_1;
    time_burn_1 = 73.8; % seconds
    propellant_mass_rate_1 = propellant_mass_1/time_burn_1;
    m_stage_2 = 5780; % kg
    propellant_mass_fraction_2 = 0.85;
    propellant_mass_2 = m_stage_2 * propellant_mass_fraction_2;
    time_burn_2 = 60.8; % seconds
    propellant_mass_rate_2 = propellant_mass_2/time_burn_2;
    if t < time_burn_1
        m = m_total - propellant_mass_rate_1*t;
    elseif t < time_burn_1 + time_burn_2
        m = m_total - propellant_mass_1 - propellant_mass_rate_2*(t-time_burn_1);
    else
        m = m_total - propellant_mass_1 - propellant_mass_2;
    end
end


% theta calculation %
function theta = theta_calculator(t, q1, q2, q3, t1)
    q1 = q1 * pi/180;
    q2 = q2 * pi/180;
    q3 = q3 * pi/180;
    time_burn_1 = 73.8; % seconds
    time_burn_2 = 60.8; % seconds
    if t < 5 % sec
        theta = pi/2;
    elseif t < time_burn_1 - 1 % sec
        theta = pi/2 - q1*t;
    elseif t <= time_burn_1 + 1 % sec
        theta = pi/2 - q1*(time_burn_1 - 1); 
    elseif t < t1
        theta = pi/2 - q1*(time_burn_1 - 1) - q2*(t - (time_burn_1 + 1));
    elseif t < time_burn_1 + time_burn_2 + 1
        theta = pi/2 - q1*(time_burn_1 - 1) - q2*(t1 - (time_burn_1 + 1)) - q3*(t - t1);
    else
        theta = pi/2 - q1*(time_burn_1 - 1) - q2*(t1 - (time_burn_1 + 1)) - q3*(time_burn_1 + time_burn_2 + 1 - t1);
    end
end
