clc;
clear;
%% maneuver %%
load('17-Apr-2023-17-25-12-answer.mat');
[~, time] = miss_distance_time_calculator(attitude);

modelname = "maneuver_b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn, 'attitude_m0', attitude*pi/180);
simIn = setVariable(simIn, 'final_time', time);

simulation_data = sim(simIn);

miss_distance = simulation_data.distance.Data(end);

fprintf("miss distance anfer manuver: %.4f\n", miss_distance);
