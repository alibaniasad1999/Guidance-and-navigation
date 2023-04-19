function miss_distance = miss_distance_calculator(k)

init; % run init script

modelname = "f";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k(1));
simIn = setVariable(simIn,'k_sigma',k(2));


simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance.Data);
miss_distance_saturation = min(simulation_data.distance_saturation.Data);

fprintf("miss distance without saturation: %.4f and with saturation %.4f\n",...
    miss_distance, miss_distance_saturation);