clear;
clc;
%% calculation of control effort in vary of LA parameter %%
LA = 20:5:80;
MD = zeros(1, length(LA)); % miss distance
for i = 1:length(LA)
    modelname = "f";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'LA',LA(i)*pi/180);
    
    simulation_data = sim(simIn);

    MD(i) = simulation_data.miss_distance.Data(end);

    fprintf('Look Angel:%.2f, i=%d\n', LA(i), i);
end

save('MD_LA_vary', "MD")