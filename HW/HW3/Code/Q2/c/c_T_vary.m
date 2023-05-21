clear;
clc;
%% calculation of control effort in vary of LA parameter %%
init;
T = [0.25, 0.5, 1];
HE_TPN = zeros(t_f/0.002+1, length(N)); % heading error
HE_APN = zeros(t_f/0.002+1, length(N)); % heading error
n_t_TPN = zeros(t_f/0.002+1, length(N)); % target maneuver
n_t_APN = zeros(t_f/0.002+1, length(N)); % target maneuver
for i = 1:length(T)
    modelname = "c";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'T',T(i));
    
    simulation_data = sim(simIn);

    HE_APN(:, i) = simulation_data.HE_APN.Data;
    HE_TPN(:, i) = simulation_data.HE_TPN.Data;

    n_t_TPN(:, i) = simulation_data.n_t_TPN.Data;
    n_t_APN(:, i) = simulation_data.n_t_APN.Data;


    fprintf('T:%f, i=%d\n', T(i), i);
end

save('n_t_HE_T_vary', "HE_APN", "HE_TPN", "n_t_TPN", "n_t_APN")