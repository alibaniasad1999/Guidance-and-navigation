%% calculation of control effort in vary of LA parameter %%

LOS_rate = [1:10, 15:5:45];
for i = 1:length(LOS_rate)
    modelname = "part_g";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'LOS_rate',LOS_rate(i)*pi/180);
    LOS_rate(i)
    simulation_data = sim(simIn);
end