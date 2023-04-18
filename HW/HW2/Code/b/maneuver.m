clc;
clear;
%% maneuver %%
load('18-Apr-2023-17-02-23-answer.mat');
[~, time] = miss_distance_time_calculator(attitude);

modelname = "maneuver_b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn, 'attitude_m0', attitude*pi/180);
simIn = setVariable(simIn, 'final_time', time);

simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance.Data);

fprintf("miss distance anfer manuver: %.4f\n", miss_distance);
