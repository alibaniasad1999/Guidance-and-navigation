% clear;
% clc;
%%%%%%%% main Vasarhelyi Guidance Law %%%%%%%%
%% parameters %%
% x_arena: arena limits
x_arena = [-100 100; % x wall
           -100 100]; % y_wall
% spheres: obstacles
spheres = [0 10 20; 0 10 20; 5 10 2]; % x y radius
% agent_number: number of agents
agent_number = 10;
% Max radius of influence - Metric distance
radius = 25;
% time: simulation time
time = 10;
% dt: time step
dt = 0.01;

[position_array, velocity_array] = simulation_function(x_arena...
    , spheres, agent_number,...
    radius, time, dt);
% plot_results(agent_number, position_array, x_arena, spheres);
% step_time = 1;
% graph_animation_creator(agent_number, position_array, x_arena, spheres,...
%     step_time, dt, radius);
plot_results_timeline(agent_number, position_array, velocity_array,...
    x_arena, spheres);
