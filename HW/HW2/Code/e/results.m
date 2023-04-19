clear;
clc;
% resulst %
%% missle %%
load('../c/19-Apr-2023-15-45-38-answer.mat');
modelname = "e";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
simulation_data = sim(simIn);


%% missle vs target %% 3D 

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
x_m = simulation_data.missle_state.Data(:, 1);
x_m = reshape(x_m, [length(x_m), 1]);
y_m = simulation_data.missle_state.Data(:, 2);
y_m = reshape(y_m, [length(y_m), 1]);
z_m = simulation_data.missle_state.Data(:, 3);
z_m = reshape(z_m, [length(z_m), 1]);


x_t = simulation_data.target_state.Data(1, 1, :);
x_t = reshape(x_t, [1, length(x_t)]);
y_t = simulation_data.target_state.Data(2, 1, :);
y_t = reshape(y_t, [1, length(y_t)]);
z_t = simulation_data.target_state.Data(3, 1, :);
z_t = reshape(z_t, [1, length(z_t)]);

x_m_no_g = simulation_data.missle_state_no_g.Data(:, 1);
x_m_no_g = reshape(x_m_no_g, [length(x_m), 1]);
y_m_no_g = simulation_data.missle_state_no_g.Data(:, 2);
y_m_no_g = reshape(y_m_no_g, [length(y_m), 1]);
z_m_no_g = simulation_data.missle_state_no_g.Data(:, 3);
z_m_no_g = reshape(z_m_no_g, [length(z_m), 1]);


plot3(x_m, y_m, z_m, 'linewidth', 2);
hold on;
plot3(x_t, y_t, z_t, '--', 'linewidth', 2);
plot3(x_m_no_g, y_m_no_g, z_m_no_g, 'linewidth', 2);
ylim([-500, 500])
legend('missle with Gravity Compensation', 'target', 'missle without Gravity Compensation',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
set(gca, 'FontSize', 16)
% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/e');
if dir_state
    print('../../Figure/e/3DoF_missle_vs_target_state','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close
%% command %%

set(gca, 'FontSize', 16)
plot(simulation_data.command, 'linewidth', 2);
hold on
plot(simulation_data.command_no_g, 'linewidth', 2);
legend('a_y with Gravity Compensation', 'a_z with Gravity Compensation',...
    'a_y without Gravity Compensation', 'a_z without Gravity Compensation',...
    'Location','southeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/e');
if dir_state
    print('../../Figure/e/command','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

%% miss distance history %%

set(gca, 'FontSize', 16)
plot(simulation_data.distance, 'linewidth', 2);
hold on
plot(simulation_data.distance_no_g, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
legend('with Gravity Compensation', 'without Gravity Compensation',...
    'Location','northeast', 'FontSize', 20);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/e');
if dir_state
    print('../../Figure/e/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

%% effort %%

set(gca, 'FontSize', 16)
plot(simulation_data.effort, 'linewidth', 2);
hold on
plot(simulation_data.effort_no_g, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
legend('with Gravity Compensation', 'without Gravity Compensation',...
    'Location','northwest', 'FontSize', 20);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/e');
if dir_state
    print('../../Figure/e/effort','-depsc');
else
    fprintf("Ooooooops\n")
end
