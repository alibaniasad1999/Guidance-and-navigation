function miss_distance = miss_distance_calculator(k)

init; % run init script

modelname = "c";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k(1));
simIn = setVariable(simIn,'k_sigma',k(2));


simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance.Data);

fprintf("miss distance: %.4f, epsilon gain:%.2f, sigma gain:%.2f \n",...
    miss_distance, k(1), k(2));