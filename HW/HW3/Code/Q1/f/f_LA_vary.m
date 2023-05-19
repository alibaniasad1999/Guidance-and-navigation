%% calculation of control effort in vary of LA parameter %%

for LA = 20:5:80
    modelname = "f";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'LA',LA*pi/180);
    
    simulation_data = sim(simIn);
end