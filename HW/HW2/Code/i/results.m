clear;
clc;
% resulst %
%% missle %%
load('../c/19-Apr-2023-15-45-38-answer.mat');
modelname = "part_i";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
simulation_data = sim(simIn);


%% missle vs target %% 3D 

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];

[~, min_disatance_index] = min(simulation_data.distance_CLOS.Data);

x_m_CLOS = simulation_data.missle_state_CLOS.Data(1:min_disatance_index, 1);
x_m_CLOS = reshape(x_m_CLOS, [length(x_m_CLOS), 1]);
y_m_CLOS = simulation_data.missle_state_CLOS.Data(1:min_disatance_index, 2);
y_m_CLOS = reshape(y_m_CLOS, [length(y_m_CLOS), 1]);
z_m_CLOS = simulation_data.missle_state_CLOS.Data(1:min_disatance_index, 3);
z_m_CLOS = reshape(z_m_CLOS, [length(z_m_CLOS), 1]);


x_t_CLOS = simulation_data.target_state_CLOS.Data(1, 1, 1:min_disatance_index);
x_t_CLOS = reshape(x_t_CLOS, [1, length(x_t_CLOS)]);
y_t_CLOS = simulation_data.target_state_CLOS.Data(2, 1, 1:min_disatance_index);
y_t_CLOS = reshape(y_t_CLOS, [1, length(y_t_CLOS)]);
z_t_CLOS = simulation_data.target_state_CLOS.Data(3, 1, 1:min_disatance_index);
z_t_CLOS = reshape(z_t_CLOS, [1, length(z_t_CLOS)]);

x_t_CLOS_with_filter = simulation_data.target_state_CLOS.Data(1, 1, :);
x_t_CLOS_with_filter = reshape(x_t_CLOS_with_filter, [1, length(x_t_CLOS_with_filter)]);
y_t_CLOS_with_filter = simulation_data.target_state_CLOS.Data(2, 1, :);
y_t_CLOS_with_filter = reshape(y_t_CLOS_with_filter, [1, length(y_t_CLOS_with_filter)]);
z_t_CLOS_with_filter = simulation_data.target_state_CLOS.Data(3, 1, :);
z_t_CLOS_with_filter = reshape(z_t_CLOS_with_filter, [1, length(z_t_CLOS_with_filter)]);

x_m_CLOS_with_filter = simulation_data.missle_state_CLOS.Data(:, 1);
x_m_CLOS_with_filter = reshape(x_m_CLOS_with_filter, [length(x_m_CLOS_with_filter), 1]);
y_m_CLOS_with_filter = simulation_data.missle_state_CLOS.Data(:, 2);
y_m_CLOS_with_filter = reshape(y_m_CLOS_with_filter, [length(x_m_CLOS_with_filter), 1]);
z_m_CLOS_with_filter = simulation_data.missle_state_CLOS.Data(:, 3);
z_m_CLOS_with_filter = reshape(z_m_CLOS_with_filter, [length(z_m_CLOS_with_filter), 1]);

subplot(1, 2, 1);
plot3(x_m_CLOS, y_m_CLOS, z_m_CLOS, 'linewidth', 2);
hold on;
plot3(x_t_CLOS, y_t_CLOS, z_t_CLOS, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('CLOS');
set(gca, 'FontSize', 16)

hold off
% _with_filter %%
subplot(1, 2, 2);
plot3(x_m_CLOS_with_filter, y_m_CLOS_with_filter, z_m_CLOS_with_filter, 'linewidth', 2);
hold on;
plot3(x_t_CLOS_with_filter, y_t_CLOS_with_filter, z_t_CLOS_with_filter, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('CLOS with filter');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/i');
if dir_state
    print('../../Figure/i/3DoF_missle_vs_target_state_CLOS','-depsc');
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
plot3(x_m_CLOS, y_m_CLOS, z_m_CLOS, 'linewidth', 2);
hold on;
plot3(x_t_CLOS, y_t_CLOS, z_t_CLOS, '--', 'linewidth', 2);
ylim([-500, 500])
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
% title('CLOS');
set(gca, 'FontSize', 16)

plot3(x_m_CLOS, y_m_CLOS, z_m_CLOS, 'linewidth', 2);
hold on;
plot3(x_t_CLOS_with_filter, y_t_CLOS_with_filter, z_t_CLOS_with_filter, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle CLOS', 'target B]CLOS',...
    'missle CLOS  with filter', 'target CLOS with filter',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('CLOS');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/i');
if dir_state
    print('../../Figure/i/3DoF_missle_vs_target_state_CLOS_all_in','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close


%% command %%

set(gca, 'FontSize', 16)
plot(simulation_data.command_CLOS, 'linewidth', 2);
hold on
plot(simulation_data.command_CLOS_with_filter, 'linewidth', 2);
legend('a_y (CLOS)', 'a_z (CLOS)',...
    'a_y (CLOS with filter)', 'a_z (CLOS with filter)',...
    'Location','southeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/i');
if dir_state
    print('../../Figure/i/command','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

%% miss distance history %%

set(gca, 'FontSize', 16)
miss_data = reshape(simulation_data.distance_CLOS.Data(1, 1, 1:min_disatance_index),...
    [length(simulation_data.distance_CLOS.Data(1, 1, 1:min_disatance_index)), 1]);
plot(simulation_data.distance_CLOS.Time(1:min_disatance_index), miss_data, 'linewidth', 2);
hold on
[~, min_disatance_index_CLOS_with_filter] = min(simulation_data.distance_CLOS_with_filter.Data);
miss_data_CLOS_with_filter = reshape(simulation_data.distance_CLOS_with_filter.Data(1, 1, 1:min_disatance_index_CLOS_with_filter),...
    [length(simulation_data.distance_CLOS_with_filter.Data(1, 1, 1:min_disatance_index_CLOS_with_filter)), 1]);
plot(simulation_data.distance_CLOS_with_filter.Time(1:min_disatance_index_CLOS_with_filter), miss_data_CLOS_with_filter, 'linewidth', 2);



% plot(simulation_data.distance_CLOS, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
legend('CLOS', 'CLOS with filter',...
    'Location','northeast', 'FontSize', 20);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/i');
if dir_state
    print('../../Figure/i/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

%% mean and std %%

fprintf("mean theta is: %.4f and std is: %.4f\n",...
    mean(simulation_data.theta), std(simulation_data.theta))

fprintf("mean theta dot is: %.4f and std is: %.4f\n",...
    mean(simulation_data.d_theta), std(simulation_data.d_theta))

fprintf("mean theta ddot is: %.4f and std is: %.4f\n",...
    mean(simulation_data.dd_theta), std(simulation_data.dd_theta))
