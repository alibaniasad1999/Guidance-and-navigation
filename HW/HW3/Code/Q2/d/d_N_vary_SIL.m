clear;
clc;
%% calculation of control effort in vary of LA parameter %%
init;
N = 3:5;
MD = zeros(1, length(N)); % miss distance
CE = zeros(1, length(N)); % control effort
y_array = zeros(t_f/0.002+1, length(N)); % y
command_array = zeros(t_f/0.002+1, length(N)); % controller command
for i = 1:length(N)
    modelname = "d";
    simIn = Simulink.SimulationInput(modelname);
    
    simIn = setVariable(simIn,'N',N(i));
    
    simulation_data = sim(simIn);

    MD(i) = abs(simulation_data.y.Data(end));
    CE(i) = simulation_data.control_effort.Data(end);

    y_array(:, i) = simulation_data.y.Data;
    command_array(:, i) = simulation_data.GNC_command.Data;

    fprintf('N:%i, i=%d\n', N(i), i);
end

save('MD_CE_N_vary_SIL', "MD", "CE", "y_array", "command_array")