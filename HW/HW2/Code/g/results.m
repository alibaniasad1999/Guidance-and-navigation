clear;
clc;
% resulst %
%% missle %%
load('../c/19-Apr-2023-15-45-38-answer.mat');
V_t0 = 300;
modelname = "g";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
simulation_data = sim(simIn);


%% missle vs target %% 3D 

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];

[~, min_disatance_index] = min(simulation_data.distance.Data);

x_m = simulation_data.missle_state.Data(1:min_disatance_index, 1);
x_m = reshape(x_m, [length(x_m), 1]);
y_m = simulation_data.missle_state.Data(1:min_disatance_index, 2);
y_m = reshape(y_m, [length(y_m), 1]);
z_m = simulation_data.missle_state.Data(1:min_disatance_index, 3);
z_m = reshape(z_m, [length(z_m), 1]);


x_t = simulation_data.target_state.Data(1, 1, 1:min_disatance_index);
x_t = reshape(x_t, [1, length(x_t)]);
y_t = simulation_data.target_state.Data(2, 1, 1:min_disatance_index);
y_t = reshape(y_t, [1, length(y_t)]);
z_t = simulation_data.target_state.Data(3, 1, 1:min_disatance_index);
z_t = reshape(z_t, [1, length(z_t)]);

x_t_new_init = simulation_data.target_state_new_init.Data(1, 1, :);
x_t_new_init = reshape(x_t_new_init, [1, length(x_t_new_init)]);
y_t_new_init = simulation_data.target_state_new_init.Data(2, 1, :);
y_t_new_init = reshape(y_t_new_init, [1, length(y_t_new_init)]);
z_t_new_init = simulation_data.target_state_new_init.Data(3, 1, :);
z_t_new_init = reshape(z_t_new_init, [1, length(z_t_new_init)]);

x_m_new_init = simulation_data.missle_state_new_init.Data(:, 1);
x_m_new_init = reshape(x_m_new_init, [length(x_m_new_init), 1]);
y_m_new_init = simulation_data.missle_state_new_init.Data(:, 2);
y_m_new_init = reshape(y_m_new_init, [length(x_m_new_init), 1]);
z_m_new_init = simulation_data.missle_state_new_init.Data(:, 3);
z_m_new_init = reshape(z_m_new_init, [length(z_m_new_init), 1]);

subplot(1, 2, 1);
plot3(x_m, y_m, z_m, 'linewidth', 2);
hold on;
plot3(x_t, y_t, z_t, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=\pi');
set(gca, 'FontSize', 16)

hold off
% new init %%
subplot(1, 2, 2);
plot3(x_m_new_init, y_m_new_init, z_m_new_init, 'linewidth', 2);
hold on;
plot3(x_t_new_init, y_t_new_init, z_t_new_init, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=0');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/g');
if dir_state
    print('../../Figure/g/3DoF_missle_vs_target_state','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close

%% all in one
f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
plot3(x_m, y_m, z_m, 'linewidth', 2);
hold on;
plot3(x_t, y_t, z_t, '--', 'linewidth', 2);
ylim([-500, 500])
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=\pi');
set(gca, 'FontSize', 16)

plot3(x_m_new_init, y_m_new_init, z_m_new_init, 'linewidth', 2);
hold on;
plot3(x_t_new_init, y_t_new_init, z_t_new_init, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle \psi = \pi', 'target \psi = \pi',...
    'missle \psi = 0', 'target \psi = 0',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=0');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/g');
if dir_state
    print('../../Figure/g/3DoF_missle_vs_target_state_all_in','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close


%% command %%

set(gca, 'FontSize', 16)
plot(simulation_data.command, 'linewidth', 2);
hold on
plot(simulation_data.command_new_init, 'linewidth', 2);
legend('a_y (\psi = \pi)', 'a_z (\psi = \pi)',...
    'a_y (\psi = 0)', 'a_z (\psi = 0)',...
    'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/g');
if dir_state
    print('../../Figure/g/command','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

%% miss distance history %%

set(gca, 'FontSize', 16)
miss_data = reshape(simulation_data.distance.Data(1, 1, 1:min_disatance_index),...
    [length(simulation_data.distance.Data(1, 1, 1:min_disatance_index)), 1]);
plot(simulation_data.distance.Time(1:min_disatance_index), miss_data, 'linewidth', 2);
hold on
[~, min_disatance_index_new_init] = min(simulation_data.distance_new_init.Data);
miss_data_new_init = reshape(simulation_data.distance_new_init.Data(1, 1, 1:min_disatance_index_new_init),...
    [length(simulation_data.distance_new_init.Data(1, 1, 1:min_disatance_index_new_init)), 1]);
plot(simulation_data.distance_new_init.Time(1:min_disatance_index_new_init), miss_data_new_init, 'linewidth', 2);


% plot(simulation_data.distance_new_init, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
legend('\psi = 180', '\psi = 0',...
    'Location','northeast', 'FontSize', 20);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/g');
if dir_state
    print('../../Figure/g/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
miss_distance_calculator(k_LOS, V_t0);


%% min velocity for good miss distance %%
load('../c/19-Apr-2023-15-45-38-answer.mat');
V_t0 = 106.9;
modelname = "g";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
simulation_data = sim(simIn);

%% missle vs target %% 3D 

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];

[~, min_disatance_index] = min(simulation_data.distance.Data);

x_m = simulation_data.missle_state.Data(1:min_disatance_index, 1);
x_m = reshape(x_m, [length(x_m), 1]);
y_m = simulation_data.missle_state.Data(1:min_disatance_index, 2);
y_m = reshape(y_m, [length(y_m), 1]);
z_m = simulation_data.missle_state.Data(1:min_disatance_index, 3);
z_m = reshape(z_m, [length(z_m), 1]);


x_t = simulation_data.target_state.Data(1, 1, 1:min_disatance_index);
x_t = reshape(x_t, [1, length(x_t)]);
y_t = simulation_data.target_state.Data(2, 1, 1:min_disatance_index);
y_t = reshape(y_t, [1, length(y_t)]);
z_t = simulation_data.target_state.Data(3, 1, 1:min_disatance_index);
z_t = reshape(z_t, [1, length(z_t)]);

x_t_new_init = simulation_data.target_state_new_init.Data(1, 1, :);
x_t_new_init = reshape(x_t_new_init, [1, length(x_t_new_init)]);
y_t_new_init = simulation_data.target_state_new_init.Data(2, 1, :);
y_t_new_init = reshape(y_t_new_init, [1, length(y_t_new_init)]);
z_t_new_init = simulation_data.target_state_new_init.Data(3, 1, :);
z_t_new_init = reshape(z_t_new_init, [1, length(z_t_new_init)]);

x_m_new_init = simulation_data.missle_state_new_init.Data(:, 1);
x_m_new_init = reshape(x_m_new_init, [length(x_m_new_init), 1]);
y_m_new_init = simulation_data.missle_state_new_init.Data(:, 2);
y_m_new_init = reshape(y_m_new_init, [length(x_m_new_init), 1]);
z_m_new_init = simulation_data.missle_state_new_init.Data(:, 3);
z_m_new_init = reshape(z_m_new_init, [length(z_m_new_init), 1]);

subplot(1, 2, 1);
plot3(x_m, y_m, z_m, 'linewidth', 2);
hold on;
plot3(x_t, y_t, z_t, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=\pi');
set(gca, 'FontSize', 16)

hold off
% new init %%
subplot(1, 2, 2);
plot3(x_m_new_init, y_m_new_init, z_m_new_init, 'linewidth', 2);
hold on;
plot3(x_t_new_init, y_t_new_init, z_t_new_init, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=0');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/g');
if dir_state
    print('../../Figure/g/3DoF_missle_vs_target_state_low_v','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close

%% all in one
f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
plot3(x_m, y_m, z_m, 'linewidth', 2);
hold on;
plot3(x_t, y_t, z_t, '--', 'linewidth', 2);
ylim([-500, 500])
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=\pi');
set(gca, 'FontSize', 16)

plot3(x_m_new_init, y_m_new_init, z_m_new_init, 'linewidth', 2);
hold on;
plot3(x_t_new_init, y_t_new_init, z_t_new_init, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle \psi = \pi', 'target \psi = \pi',...
    'missle \psi = 0', 'target \psi = 0',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('\psi=0');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/g');
if dir_state
    print('../../Figure/g/3DoF_missle_vs_target_state_all_in_low_v','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close
miss_distance_calculator(k_LOS, V_t0);
