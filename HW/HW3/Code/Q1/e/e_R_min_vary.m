%% calculation of control effort in vary of R_min parameter %%

R_min = [1:10, 15:5:100];

for i = 1:length(R_min)
    modelname = "e";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'R_min',R_min(i));
    R_min(i)
    simulation_data = sim(simIn);
end