clear;
clc;
%% APN %%
load('n_t_HE_T_vary.mat')
set(gca, 'FontSize', 16)
tout = 0:0.002:15;
plot(tout, HE_TPN(:, 1)*180/pi, 'LineWidth', 2);
hold on;
plot(tout, HE_APN(:, 1)*180/pi, 'LineWidth', 2);

xlabel('$T_f(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Heading Error(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('TPN', 'APN', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/c');
if dir_state
    print('../../../Figure/Q2/c/HE_25','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;


set(gca, 'FontSize', 16)
tout = 0:0.002:15;
plot(tout, HE_TPN(:, 2)*180/pi, 'LineWidth', 2);
hold on;
plot(tout, HE_APN(:, 2)*180/pi, 'LineWidth', 2);

xlabel('$T_f(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Heading Error(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('TPN', 'APN', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/c');
if dir_state
    print('../../../Figure/Q2/c/HE_5','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;
set(gca, 'FontSize', 16)
tout = 0:0.002:15;
plot(tout, HE_TPN(:, 3)*180/pi, 'LineWidth', 2);
hold on;
plot(tout, HE_APN(:, 3)*180/pi, 'LineWidth', 2);

xlabel('$T_f(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Heading Error(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('TPN', 'APN', 'Location','northeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/c');
if dir_state
    print('../../../Figure/Q2/c/HE_1','-depsc');
else
    fprintf("Ooooooops\n")
end
