function miss_distance = miss_distance_calculator(k)

init; % run init script

modelname = "part_j";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'k_epsilon_lead_angle',k(1));
simIn = setVariable(simIn,'k_sigma_lead_angle',k(2));
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance_lead_angle.Data);
miss_distance_CLOS = min(simulation_data.distance_CLOS.Data);

fprintf("miss distance CLOS: %.4f and CLOS with lead Angle: %.4f\n", ...
    miss_distance_CLOS, miss_distance);