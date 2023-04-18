function [miss_distance, time] = miss_distance_time_calculator(attitude)

init; % run init script

modelname = "b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'attitude_m0',attitude*pi/180);

simulation_data = sim(simIn);

[miss_distance, index] = min(simulation_data.distance.Data);
time = simulation_data.distance.Time(index);