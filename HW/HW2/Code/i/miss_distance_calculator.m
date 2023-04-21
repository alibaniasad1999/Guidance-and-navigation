function  miss_distance_calculator(k)

init; % run init script


modelname = "part_i";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k(1));
simIn = setVariable(simIn,'k_sigma',k(2));


simulation_data = sim(simIn);

miss_distance_CLOS = min(simulation_data.distance_CLOS.Data);
miss_distance_CLOS_with_filter = min(simulation_data.distance_CLOS_with_filter.Data);

fprintf("CLOS miss distance: %.4f CLOS with filter miss distance :%.4f \n",...
    miss_distance_CLOS, miss_distance_CLOS_with_filter);