clear;
clc;
%% calculation of control effort in vary of R_min parameter %%

R_min = [0.01:0.01:0.1, 0.2:0.1:0.9, 1:10, 15:5:100];
MD = zeros(1, length(R_min)); % miss distance

for i = 1:length(R_min)
    modelname = "e";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'R_min',R_min(i));
    simulation_data = sim(simIn);

    MD(i) = simulation_data.miss_distance.Data(end);

    fprintf('R min:%.2f, i=%d\n', R_min(i), i);
end

save('MD_CE_R_min_vary', "MD")