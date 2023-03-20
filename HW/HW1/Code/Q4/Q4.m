clc;
clear;
%% Q4 (Kalman vs los pass) %%
Q4_data = sim('Q4_simulink.slx'); % run simulink

%% LPF %%
subplot(2, 1, 1)
plot(Q4_data.LPF_position, 'r', 'linewidth', 2);
hold on
plot(Q4_data.position, ':k', 'linewidth', 4);

legend('LPF', 'Simulated', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
ylabel('Position', 'interpreter', 'latex', 'FontSize', 24);
title('')


subplot(2, 1, 2)
plot(Q4_data.LPF_velocity, 'r', 'linewidth', 2);
hold on
plot(Q4_data.velocity, ':k', 'linewidth', 4);

legend('LPF', 'Simulated', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
ylabel('Velocity', 'interpreter', 'latex', 'FontSize', 24);
title('')
set(gcf,'Position',[500 500 1000 800])
print('../../Figure/Q1/LPF','-depsc');
hold off

%% Kalman %%
subplot(2, 1, 1)
plot(Q4_data.Kalman_position, 'r', 'linewidth', 2);
hold on
plot(Q4_data.position, ':k', 'linewidth', 4);

legend('Kalman Filter', 'Simulated', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
ylabel('Position', 'interpreter', 'latex', 'FontSize', 24);
title('')


subplot(2, 1, 2)
plot(Q4_data.Kalman_velocity, 'r', 'linewidth', 2);
hold on
plot(Q4_data.velocity, ':k', 'linewidth', 4);

legend('Kalman Filter', 'Simulated', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
ylabel('Velocity', 'interpreter', 'latex', 'FontSize', 24);
title('')
set(gcf,'Position',[500 500 1000 800])
print('../../Figure/Q1/Kalman','-depsc');

