clear;
clc;
%%%%%%%% main Vasarhelyi Guidance Law %%%%%%%%
%% parameters %%
% x_arena: arena limits
x_arena = [-100 100; % x wall
           -100 100]; % y_wall
% spheres: obstacles
spheres = [0 10 20; 0 10 20; 5 10 20]; % x y radius
% agent_number: number of agents
agent_number = 50;
% time: simulation time
time = 1;
% dt: time step
dt = 0.01;

position_array = simulation_function(x_arena, spheres, agent_number, time, dt);
plot_results(agent_number, position_array, x_arena, spheres);
