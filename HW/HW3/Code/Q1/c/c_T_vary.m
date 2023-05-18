%% calculation of control effort in vary of N parameter %%


for T = 0.05:0.05:1
    modelname = "c";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'T',T);
    
    simulation_data = sim(simIn);
end