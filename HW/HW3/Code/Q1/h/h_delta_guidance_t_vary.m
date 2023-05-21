clear;
clc;
%% calculation of control effort in vary of LA parameter %%

delta_guidance_t = [0.01, 0.05:0.05:0.5, 0.6:0.1:1];
MD = zeros(1, length(delta_guidance_t)); % miss distance

for i = 1:length(delta_guidance_t)
    modelname = "h";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'delta_guidance_t',delta_guidance_t(i));

    simulation_data = sim(simIn);

    MD(i) = simulation_data.miss_distance.Data(end);

    fprintf('Delta T:%.2f, i=%d\n', delta_guidance_t(i), i);
end

save('MD_delta_guidance_t_vary', "MD")