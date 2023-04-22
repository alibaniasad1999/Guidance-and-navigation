clear;
clc;
% resulst %
%% missle %%
load('../c/19-Apr-2023-15-45-38-answer.mat');
load('../j/22-Apr-2023-17-19-12-answer.mat')
modelname = "part_l";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'k_epsilon_lead_angle',k(1));
simIn = setVariable(simIn,'k_sigma_lead_angle',k(2));
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
simulation_data = sim(simIn);




%% miss distance history %%
f = figure;
width=600;
height=900;
f.Position = [15 15 width height];
set(gca, 'FontSize', 16)
subplot(2, 1, 1)
[~, min_disatance_index_lead_angle] = min(simulation_data.distance_lead_angle.Data);
miss_data_lead_angle = reshape(simulation_data.distance_lead_angle.Data(1, 1, 1:min_disatance_index_lead_angle),...
    [length(simulation_data.distance_lead_angle.Data(1, 1, 1:min_disatance_index_lead_angle)), 1]);
plot(simulation_data.distance_lead_angle.Time(1:min_disatance_index_lead_angle), miss_data_lead_angle, 'linewidth', 2);



% plot(simulation_data.distance_lead_angle_limited, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
title('Miss Distance');
axis tight

subplot(2, 1, 2)
plot(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle),...
    simulation_data.beam_angle.Data(1:min_disatance_index_lead_angle)*180/pi, 'linewidth', 2);
hold on 
plot(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle),3*ones(1, length(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle))), '--r', 'linewidth', 2)
plot(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle),-3*ones(1, length(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle))), '--r', 'linewidth', 2)

title('Beam Angle');
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Beam angle (deg)', 'interpreter', 'latex', 'FontSize', 24);
axis tight


[dir_state, ~, ~] = mkdir('../../Figure/l');
if dir_state
    print('../../Figure/l/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close


%% missle vs target %% 3D 

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];

[~, min_disatance_index] = min(simulation_data.distance_lead_angle_limited.Data);
[~, min_disatance_index_with_filter] = min(simulation_data.distance_lead_angle.Data);

x_m_lead_angle_limited = simulation_data.missle_state_lead_angle_limited.Data(1:min_disatance_index, 1);
x_m_lead_angle_limited = reshape(x_m_lead_angle_limited, [length(x_m_lead_angle_limited), 1]);
y_m_lead_angle_limited = simulation_data.missle_state_lead_angle_limited.Data(1:min_disatance_index, 2);
y_m_lead_angle_limited = reshape(y_m_lead_angle_limited, [length(y_m_lead_angle_limited), 1]);
z_m_lead_angle_limited = simulation_data.missle_state_lead_angle_limited.Data(1:min_disatance_index, 3);
z_m_lead_angle_limited = reshape(z_m_lead_angle_limited, [length(z_m_lead_angle_limited), 1]);


x_t_lead_angle_limited = simulation_data.target_state_lead_angle_limited.Data(1, 1, 1:min_disatance_index);
x_t_lead_angle_limited = reshape(x_t_lead_angle_limited, [1, length(x_t_lead_angle_limited)]);
y_t_lead_angle_limited = simulation_data.target_state_lead_angle_limited.Data(2, 1, 1:min_disatance_index);
y_t_lead_angle_limited = reshape(y_t_lead_angle_limited, [1, length(y_t_lead_angle_limited)]);
z_t_lead_angle_limited = simulation_data.target_state_lead_angle_limited.Data(3, 1, 1:min_disatance_index);
z_t_lead_angle_limited = reshape(z_t_lead_angle_limited, [1, length(z_t_lead_angle_limited)]);

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

subplot(1, 2, 1);
plot3(x_m_lead_angle_limited, y_m_lead_angle_limited, z_m_lead_angle_limited, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle_limited, y_t_lead_angle_limited, z_t_lead_angle_limited, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle', 'target',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('Lead Angle limited');
set(gca, 'FontSize', 16)

hold off
% _with_filter %%
subplot(1, 2, 2);
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
title('Lead Angle');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/l');
if dir_state
    print('../../Figure/l/3DoF_missle_vs_target_state_lead_angle_limited','-depsc');
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
plot3(x_m_lead_angle_limited, y_m_lead_angle_limited, z_m_lead_angle_limited, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle_limited, y_t_lead_angle_limited, z_t_lead_angle_limited, '--', 'linewidth', 2);
ylim([-500, 500])
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
% title('CLOS');
set(gca, 'FontSize', 16)

plot3(x_m_lead_angle, y_m_lead_angle, z_m_lead_angle, 'linewidth', 2);
hold on;
plot3(x_t_lead_angle, y_t_lead_angle, z_t_lead_angle, '--', 'linewidth', 2);
ylim([-500, 500])
legend('missle CLOS', 'target CLOS',...
    'missle lead angle', 'target Lead Angle',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
title('CLOS');
set(gca, 'FontSize', 16)

% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/');
if dir_state
    print('../../Figure/l/3DoF_missle_vs_target_state_lead_angle_limited_all_in','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
close

%% command %%

set(gca, 'FontSize', 16)
plot(simulation_data.command_lead_angle_limited, 'linewidth', 2);
hold on
plot(simulation_data.command_lead_angle, 'linewidth', 2);
legend('a_y (Lead Angle limited)', 'a_z (Lead Angle limited)',...
    'a_y (Lead Angle)', 'a_z (Lead Angle)',...
    'Location','southeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/l');
if dir_state
    print('../../Figure/l/command','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off

%% miss distance history %%

set(gca, 'FontSize', 16)
miss_data = reshape(simulation_data.distance_lead_angle_limited.Data(1, 1, 1:min_disatance_index),...
    [length(simulation_data.distance_lead_angle_limited.Data(1, 1, 1:min_disatance_index)), 1]);
plot(simulation_data.distance_lead_angle_limited.Time(1:min_disatance_index), miss_data, 'linewidth', 2);
hold on
[~, min_disatance_index_lead_angle] = min(simulation_data.distance_lead_angle.Data);
miss_data_lead_angle = reshape(simulation_data.distance_lead_angle.Data(1, 1, 1:min_disatance_index_lead_angle),...
    [length(simulation_data.distance_lead_angle.Data(1, 1, 1:min_disatance_index_lead_angle)), 1]);
plot(simulation_data.distance_lead_angle.Time(1:min_disatance_index_lead_angle), miss_data_lead_angle, 'linewidth', 2);



% plot(simulation_data.distance_lead_angle_limited, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
legend('Lead Angle limited', 'Lead Angle',...
    'Location','northeast', 'FontSize', 20);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/l');
if dir_state
    print('../../Figure/l/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off



