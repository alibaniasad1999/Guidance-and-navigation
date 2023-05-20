clear;
clc;
%% calculation of control effort in vary of saturation parameter %%

saturation_lim = 1:0.5:10;
MD = zeros(1, length(saturation_lim)); % miss distance
CE = zeros(1, length(saturation_lim)); % control effort
for i = 1:length(saturation_lim)
    modelname = "d";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'saturation_lim',saturation_lim(i));
    simulation_data = sim(simIn);

    MD(i) = simulation_data.miss_distance.Data(end);
    CE(i) = simulation_data.control_effort.Data(end);

    fprintf('saturation:%.2f, i=%d\n', saturation_lim(i), i);
end

save('MD_CE_saturation_vary', "CE", "MD")