%% calculation of control effort in vary of N parameter %%


for N = 3:5
    modelname = "b";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'N',N);
    
    simulation_data = sim(simIn);
end