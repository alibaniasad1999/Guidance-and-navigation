clear;
clc;
% resulst %
%% missle %%
load('../c/19-Apr-2023-15-45-38-answer.mat');
modelname = "f";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
simulation_data = sim(simIn);


%% command %%

set(gca, 'FontSize', 16)
plot(simulation_data.command, 'linewidth', 2);
hold on
plot(simulation_data.command_with_saturation, 'linewidth', 2);
legend('a_y with saturation', 'a_z with saturation',...
    'a_y without saturation', 'a_z without saturation',...
    'Location','southeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/f');
if dir_state
    print('../../Figure/f/command','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

%% miss distance history %%

set(gca, 'FontSize', 16)
plot(simulation_data.distance, 'linewidth', 2);
hold on
plot(simulation_data.distance_saturation, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
legend('with saturation', 'without saturation',...
    'Location','northeast', 'FontSize', 20);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/f');
if dir_state
    print('../../Figure/f/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

