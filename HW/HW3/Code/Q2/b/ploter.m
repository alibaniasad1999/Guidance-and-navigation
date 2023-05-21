clear;
clc;
%% APN %%
simulation_data = sim('b.slx');
load('../a/MD_CE_N_vary.mat')
set(gca, 'FontSize', 16)
plot(simulation_data.tout, simulation_data.y.Data, 'LineWidth', 2);
hold on;
plot(simulation_data.tout, y_array(:, 2), 'LineWidth', 2);

xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('APN', 'TPN', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/b');
if dir_state
    print('../../../Figure/Q2/b/y','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;
set(gca, 'FontSize', 16)
plot(simulation_data.tout, simulation_data.GNC_command.Data, 'LineWidth', 2);
hold on
plot(simulation_data.tout, command_array(:, 2), 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Command(m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('APN', 'TPN', 'Location','northeast', 'FontSize', 20);
[dir_state, ~, ~] = mkdir('../../../Figure/Q2/b');
if dir_state
    print('../../../Figure/Q2/b/command','-depsc');
else
    fprintf("Ooooooops\n")
end