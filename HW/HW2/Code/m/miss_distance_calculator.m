function miss_distance = miss_distance_calculator(k)

init; % run init script

modelname = "part_m";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'k_epsilon_lead_angle',k(1));
simIn = setVariable(simIn,'k_sigma_lead_angle',k(2));
simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance_lead_angle_2.Data);

fprintf("with k epsilon: %.4f and k sigma: %.4f, miss distance is: %.4f\n", ...
    k(1), k(2), miss_distance);