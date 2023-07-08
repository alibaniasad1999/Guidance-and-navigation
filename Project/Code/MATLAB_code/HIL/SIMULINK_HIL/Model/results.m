clc;
clear;
%% plot results %%
load('position_data.mat');
load('init.mat');
step_time = 0.1;
dt = 0.01;
radius = 25;
position = reshape(x', [2, 20, length(x)]);
graph_animation_creator(20, position, x_arena, spheres, step_time,...
    dt, radius)