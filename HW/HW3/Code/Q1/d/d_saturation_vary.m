%% calculation of control effort in vary of N parameter %%


for saturation_lim = 1:0.5:10
    modelname = "d";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'saturation_lim',saturation_lim);
    saturation_lim
    simulation_data = sim(simIn);
end