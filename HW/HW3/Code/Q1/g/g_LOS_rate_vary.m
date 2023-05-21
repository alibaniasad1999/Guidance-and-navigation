clear;
clc;
%% calculation of control effort in vary of LA parameter %%

LOS_rate = [1:10, 15:5:45];
MD = zeros(1, length(LOS_rate)); % miss distance
for i = 1:length(LOS_rate)
    modelname = "part_g";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'LOS_rate',LOS_rate(i)*pi/180);

    simulation_data = sim(simIn);

    MD(i) = simulation_data.miss_distance.Data(end);

    fprintf('LOS rotation:%.2f, i=%d\n', LOS_rate(i), i);
end


save('MD_LOS_rate_vary', "MD")