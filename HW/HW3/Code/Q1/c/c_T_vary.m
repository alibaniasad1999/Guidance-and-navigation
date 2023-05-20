clear;
clc;
%% calculation of control effort in vary of T parameter %%
T = [0.05:0.05:1, 1:0.1:5, 6:10];
MD = zeros(1, length(T)); % miss distance
CE = zeros(1, length(T)); % control effort

for i = 1:length(T)
    modelname = "c";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'T',T(i));
    simulation_data = sim(simIn);

    MD(i) = simulation_data.miss_distance.Data(end);
    CE(i) = simulation_data.control_effort.Data(end);
    fprintf('T:%.3f, i=%d\n', T(i), i);
end

save('MD_CE_T_vary', "CE", "MD")