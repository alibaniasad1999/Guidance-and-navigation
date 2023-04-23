function miss_distance = miss_distance_calculator(k)

init; % run init script

modelname = "part_m";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'k_epsilon_lead_angle',k(1));
simIn = setVariable(simIn,'k_sigma_lead_angle',k(2));
simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance_lead_angle2.Data);
miss_distance1 = min(simulation_data.distance_lead_angle.Data);
miss_distance2 = min(simulation_data.distance_lead_angle1.Data);
fprintf("scenario I: %.4f II %.4f, II: %.4f\n", ...
    miss_distance1, miss_distance2 , miss_distance);