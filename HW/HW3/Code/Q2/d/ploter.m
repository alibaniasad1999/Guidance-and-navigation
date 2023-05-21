load('MD_CE_N_vary_SIL.mat')
command_array_SIL = command_array;
y_array_SIL = y_array;
load('../a/MD_CE_N_vary.mat', 'command_array', 'y_array');
tout = 0:0.002:15;

%% y %%
set(gca, 'FontSize', 16)
plot(tout, y_array_SIL(:, 1), 'LineWidth', 2);
hold on
plot(tout, y_array(:, 1), 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('SIL', 'MIL', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/d');
if dir_state
    print('../../../Figure/Q2/d/y_1','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;


set(gca, 'FontSize', 16)
plot(tout, y_array_SIL(:, 2), 'LineWidth', 2);
hold on
plot(tout, y_array(:, 2), 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('SIL', 'MIL', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/d');
if dir_state
    print('../../../Figure/Q2/d/y_2','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;

set(gca, 'FontSize', 16)
plot(tout, y_array_SIL(:, 3), 'LineWidth', 2);
hold on
plot(tout, y_array(:, 3), 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('SIL', 'MIL', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/d');
if dir_state
    print('../../../Figure/Q2/d/y_3','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;
%% command %%
set(gca, 'FontSize', 16)
plot(tout, command_array_SIL(:, 1), 'LineWidth', 2);
hold on
plot(tout, command_array(:, 1), 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Command(m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('SIL', 'MIL', 'Location','southwest', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/d');
if dir_state
    print('../../../Figure/Q2/d/command_1','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;


set(gca, 'FontSize', 16)
plot(tout, command_array_SIL(:, 2), 'LineWidth', 2);
hold on
plot(tout, command_array(:, 2), 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Command(m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('SIL', 'MIL', 'Location','southwest', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/d');
if dir_state
    print('../../../Figure/Q2/d/command_2','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;

set(gca, 'FontSize', 16)
plot(tout, command_array_SIL(:, 3), 'LineWidth', 2);
hold on
plot(tout, command_array(:, 3), 'LineWidth', 2);
xlabel('Time$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Command(m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('SIL', 'MIL', 'Location','southwest', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/d');
if dir_state
    print('../../../Figure/Q2/d/command_3','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;

