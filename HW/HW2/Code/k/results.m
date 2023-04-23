clear;
clc;
% resulst %
%% missle %%
load('../c/19-Apr-2023-15-45-38-answer.mat');
load('../j/22-Apr-2023-17-19-12-answer.mat')
modelname = "part_k";
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



% plot(simulation_data.distance_CLOS, 'linewidth', 2);
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
plot(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle),3/2*ones(1, length(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle))), '--r', 'linewidth', 2)
plot(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle),-3/2*ones(1, length(simulation_data.beam_angle.Time(1:min_disatance_index_lead_angle))), '--r', 'linewidth', 2)

title('Beam Angle');
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Beam angle (deg)', 'interpreter', 'latex', 'FontSize', 24);
axis tight


[dir_state, ~, ~] = mkdir('../../Figure/k');
if dir_state
    print('../../Figure/k/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off


