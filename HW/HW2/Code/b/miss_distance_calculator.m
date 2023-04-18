function miss_distance = miss_distance_calculator(attitude)

init; % run init script

modelname = "b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'attitude_m0',attitude*pi/180);

simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance.Data);

fprintf("with theta: %.4f and psi: %.4f, miss distance is: %.4f\n", ...
    attitude(1), attitude(2), miss_distance);