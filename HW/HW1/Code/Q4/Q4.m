clc;
clear;
%% Q4 (Kalman vs los pass) %%
Q4_data = sim('Q4_simulink.slx'); % run simulink

%% real vs noisy
plot(Q4_data.position, 'r', 'linewidth', 2);
hold on
plot(Q4_data.noisy_position, ':k', 'linewidth', 2);

legend('Real Position', 'Noisy Position',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
ylabel('Position', 'interpreter', 'latex', 'FontSize', 24);
title('')
print('../../Figure/Q4/real_vs_noisy','-depsc');
hold off
close all
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
print('../../Figure/Q4/LPF','-depsc');
hold off
close all

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
print('../../Figure/Q4/Kalman','-depsc');

