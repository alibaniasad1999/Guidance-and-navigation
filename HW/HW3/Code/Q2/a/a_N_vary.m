%% calculation of control effort in vary of LA parameter %%

for N = 3:5
    modelname = "a";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'N',N);
    
    simulation_data = sim(simIn);
end