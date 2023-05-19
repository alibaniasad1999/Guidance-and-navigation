%% calculation of control effort in vary of LA parameter %%

delta_guidance_t = [0.01, 0.05:0.05:0.5, 0.6:0.1:1];
for i = 1:length(delta_guidance_t)
    modelname = "h";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'delta_guidance_t',delta_guidance_t(i));
    delta_guidance_t(i)
    simulation_data = sim(simIn);
end