clear;
clc;
% resulst %
%% missle %%
modelname = "part_m";
simIn = Simulink.SimulationInput(modelname);
simulation_data = sim(simIn);


%% missle vs target %% 3D 

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];

[~, min_disatance_index] = min(simulation_data.distance_lead_angle1.Data);
[~, min_disatance_index_with_filter] = min(simulation_data.distance_lead_angle.Data);

x_m_lead_angle1 = simulation_data.missle_state_lead_angle1.Data(1:min_disatance_index, 1);
x_m_lead_angle1 = reshape(x_m_lead_angle1, [length(x_m_lead_angle1), 1]);
y_m_lead_angle1 = simulation_data.missle_state_lead_angle1.Data(1:min_disatance_index, 2);
y_m_lead_angle1 = reshape(y_m_lead_angle1, [length(y_m_lead_angle1), 1]);
z_m_lead_angle1 = simulation_data.missle_state_lead_angle1.Data(1:min_disatance_index, 3);
z_m_lead_angle1 = reshape(z_m_lead_angle1, [length(z_m_lead_angle1), 1]);


x_t_lead_angle1 = simulation_data.target_state_lead_angle1.Data(1, 1, 1:min_disatance_index);
x_t_lead_angle1 = reshape(x_t_lead_angle1, [1, length(x_t_lead_angle1)]);
y_t_lead_angle1 = simulation_data.target_state_lead_angle1.Data(2, 1, 1:min_disatance_index);
y_t_lead_angle1 = reshape(y_t_lead_angle1, [1, length(y_t_lead_angle1)]);
z_t_lead_angle1 = simulation_data.target_state_lead_angle1.Data(3, 1, 1:min_disatance_index);
z_t_lead_angle1 = reshape(z_t_lead_angle1, [1, length(z_t_lead_angle1)]);

x_t_lead_angle = simulation_data.target_state_lead_angle.Data(1, 1, 1:min_disatance_index_with_filter);
x_t_lead_angle = reshape(x_t_lead_angle, [1, length(x_t_lead_angle)]);
y_t_lead_angle = simulation_data.target_state_lead_angle.Data(2, 1, 1:min_disatance_index_with_filter);
y_t_lead_angle = reshape(y_t_lead_angle, [1, length(y_t_lead_angle)]);
z_t_lead_angle = simulation_data.target_state_lead_angle.Data(3, 1, 1:min_disatance_index_with_filter);
z_t_lead_angle = reshape(z_t_lead_angle, [1, length(z_t_lead_angle)]);

x_m_lead_angle = simulation_data.missle_state_lead_angle.Data(1:min_disatance_index_with_filter, 1);
x_m_lead_angle = reshape(x_m_lead_angle, [length(x_m_lead_angle), 1]);
y_m_lead_angle = simulation_data.missle_state_lead_angle.Data(1:min_disatance_index_with_filter, 2);
y_m_lead_angle = reshape(y_m_lead_angle, [length(x_m_lead_angle), 1]);
z_m_lead_angle = simulation_data.missle_state_lead_angle.Data(1:min_disatance_index_with_filter, 3);
z_m_lead_angle = reshape(z_m_lead_angle, [length(z_m_lead_angle), 1]);

[~, min_disatance_index] = min(simulation_data.distance_lead_angle2.Data);
[~, min_disatance_index_with_filter] = min(simulation_data.distance_lead_angle.Data);

x_m_lead_angle2 = simulation_data.missle_state_lead_angle2.Data(1:min_disatance_index, 1);
x_m_lead_angle2 = reshape(x_m_lead_angle2, [length(x_m_lead_angle2), 1]);
y_m_lead_angle2 = simulation_data.missle_state_lead_angle2.Data(1:min_disatance_index, 2);
y_m_lead_angle2 = reshape(y_m_lead_angle2, [length(y_m_lead_angle2), 1]);
z_m_lead_angle2 = simulation_data.missle_state_lead_angle2.Data(1:min_disatance_index, 3);
z_m_lead_angle2 = reshape(z_m_lead_angle2, [length(z_m_lead_angle2), 1]);


x_t_lead_angle2 = simulation_data.target_state_lead_angle2.Data(1, 1, 1:min_disatance_index);
x_t_lead_angle2 = reshape(x_t_lead_angle2, [1, length(x_t_lead_angle2)]);
y_t_lead_angle2 = simulation_data.target_state_lead_angle2.Data(2, 1, 1:min_disatance_index);
y_t_lead_angle2 = reshape(y_t_lead_angle2, [1, length(y_t_lead_angle2)]);
z_t_lead_angle2 = simulation_data.target_state_lead_angle2.Data(3, 1, 1:min_disatance_index);
z_t_lead_angle2 = reshape(z_t_lead_angle2, [1, length(z_t_lead_angle2)]);

subplot(1, 3, 1);
plot3(x_m_lead_angle, y_m_lead_angle, z_m_lead_angle, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle, y_t_lead_angle, z_t_lead_angle, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('Scenario I');
set(gca, 'FontSize', 16)

hold off
% _with_filter %%
subplot(1, 3, 2);
plot3(x_m_lead_angle1, y_m_lead_angle1, z_m_lead_angle1, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle1, y_t_lead_angle1, z_t_lead_angle1, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('Scenario II');
set(gca, 'FontSize', 16)

subplot(1, 3, 3);
plot3(x_m_lead_angle2, y_m_lead_angle2, z_m_lead_angle2, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle2, y_t_lead_angle2, z_t_lead_angle2, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('Scenario III');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/m');
if dir_state
    print('../../Figure/m/3DoF_missle_vs_target_state_lead_angle_all_scenario','-depsc');
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
plot3(x_m_lead_angle, y_m_lead_angle, z_m_lead_angle, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle, y_t_lead_angle, z_t_lead_angle, '--', 'linewidth', 2);
ylim([-500, 500])
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
% title('CLOS');
set(gca, 'FontSize', 16)

plot3(x_m_lead_angle1, y_m_lead_angle1, z_m_lead_angle1, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle1, y_t_lead_angle1, z_t_lead_angle1, '--', 'linewidth', 2);

plot3(x_m_lead_angle2, y_m_lead_angle2, z_m_lead_angle2, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle2, y_t_lead_angle2, z_t_lead_angle2, '--', 'linewidth', 2);

ylim([-500, 500])
legend('missle scenario I', 'target scenario I',...
    'missle scenario II', 'target scenario II',...
    'missle scenario III', 'target scenario III',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/m');
if dir_state
    print('../../Figure/m/3DoF_missle_vs_target_state_lead_angle1_all_in','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close


%% command %%

set(gca, 'FontSize', 16)
plot(simulation_data.command_lead_angle, 'linewidth', 2);
hold on
plot(simulation_data.command_lead_angle1, 'linewidth', 2);
plot(simulation_data.command_lead_angle1, 'linewidth', 2);
legend('a_y (missle scenario I)', 'a_z (missle scenario I)',...
    'a_y (missle scenario II)', 'a_z (missle scenario II)',...
    'a_y (missle scenario III)', 'a_z (missle scenario III)',...
    'Location','southeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/m');
if dir_state
    print('../../Figure/m/command','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close

%% miss distance history %%

set(gca, 'FontSize', 16)
[~, min_disatance_index_lead_angle] = min(simulation_data.distance_lead_angle.Data);
miss_data_lead_angle = reshape(simulation_data.distance_lead_angle.Data(1, 1, 1:min_disatance_index_lead_angle),...
    [length(simulation_data.distance_lead_angle.Data(1, 1, 1:min_disatance_index_lead_angle)), 1]);
hold on
plot(simulation_data.distance_lead_angle.Time(1:min_disatance_index_lead_angle), miss_data_lead_angle, 'linewidth', 2);
miss_data = reshape(simulation_data.distance_lead_angle1.Data(1, 1, 1:min_disatance_index),...
    [length(simulation_data.distance_lead_angle1.Data(1, 1, 1:min_disatance_index)), 1]);
plot(simulation_data.distance_lead_angle1.Time(1:min_disatance_index), miss_data, 'linewidth', 2);

miss_data = reshape(simulation_data.distance_lead_angle2.Data(1, 1, 1:min_disatance_index),...
    [length(simulation_data.distance_lead_angle2.Data(1, 1, 1:min_disatance_index)), 1]);
plot(simulation_data.distance_lead_angle2.Time(1:min_disatance_index), miss_data, 'linewidth', 2);



% plot(simulation_data.distance_lead_angle1, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
legend('scenario I', 'scenario II', 'scenario III',...
    'Location','northeast', 'FontSize', 20);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/m');
if dir_state
    print('../../Figure/m/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off


