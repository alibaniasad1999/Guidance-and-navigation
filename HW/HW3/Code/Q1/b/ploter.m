%% part b %%
%% command plot %%
time_2_plot = simulation_data.tout(end)-0.2; % sec
time_index = find(simulation_data.tout==time_2_plot);

set(gca, 'FontSize', 16)
plot(simulation_data.tout(1:time_index), simulation_data.guidance_command.Data(1:time_index, 2)...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Guidance Command Y axis(m$/\sec^2)$', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/b');
if dir_state
    print(append('../../../Figure/Q1/b/GC_y_', string(N)),'-depsc');
else
    fprintf("Ooooooops\n")
end

set(gca, 'FontSize', 16)
plot(simulation_data.tout(1:time_index), simulation_data.guidance_command.Data(1:time_index, 3)...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Guidance Command Z axis(m$/\sec^2)$', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
if dir_state
    print(append('../../../Figure/Q1/b/GC_z_', string(N)),'-depsc');
else
    fprintf("Ooooooops\n")
end

set(gca, 'FontSize', 16)
plot(simulation_data.tout(1:time_index), simulation_data.Omega.Data(1:time_index, 2)...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('$\Omega_y$(rad$/\sec)$', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
if dir_state
    print(append('../../../Figure/Q1/b/Omega_y_', string(N)), '-depsc');
else
    fprintf("Ooooooops\n")
end

set(gca, 'FontSize', 16)
plot(simulation_data.tout(1:time_index), simulation_data.Omega.Data(1:time_index, 3)...
    , 'b', 'LineWidth', 2);
xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('$\Omega_z$(rad$/\sec)$', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
if dir_state
    print(append('../../../Figure/Q1/b/Omega_z_', string(N)),'-depsc');
else
    fprintf("Ooooooops\n")
end