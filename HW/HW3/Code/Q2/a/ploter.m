load('MD_CE_N_vary.mat')
set(gca, 'FontSize', 16)
plot(simulation_data.tout, y_array, 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('y(m)', 'interpreter', 'latex', 'FontSize', 24);
% axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('N=3', 'N=4', 'N=5', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/a');
if dir_state
    print('../../../Figure/Q2/a/y','-depsc');
else
    fprintf("Ooooooops\n")
end

set(gca, 'FontSize', 16)
plot(simulation_data.tout, command_array, 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Command(m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
axis([0, 15 -5 5]) 
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('N=3', 'N=4', 'N=5', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/a');
if dir_state
    print('../../../Figure/Q2/a/command','-depsc');
else
    fprintf("Ooooooops\n")
end