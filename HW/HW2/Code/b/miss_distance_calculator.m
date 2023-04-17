function miss_distance = miss_distance_calculator(attitude)

init; % run init script

modelname = "b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'attitude_m0',attitude*pi/180);

simulation_data = sim(simIn);

miss_distance = simulation_data.distance.Data(end);