clear;
clc;
% resulst %
%% missle %%
load('18-Apr-2023-17-02-23-answer.mat');
modelname = "b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'attitude_m0',attitude*pi/180);
simulation_data = sim(simIn);
% state %
set(gca, 'FontSize', 16)
plot(simulation_data.missle_state, 'linewidth', 2);
legend('X', 'Y', 'Z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('State(m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight;
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/missle_state','-depsc');
else
    fprintf("Ooooooops\n")
end

% attitude %
set(gca, 'FontSize', 16)
plot(simulation_data.missle_attitude, 'linewidth', 2);
legend('\theta', '\psi', 'Location','southwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Attitude(deg)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/missle_attitude','-depsc');
else
    fprintf("Ooooooops\n")
end

% Velocity %
set(gca, 'FontSize', 16)
plot(simulation_data.V_missle, 'linewidth', 2);
% legend('X', 'Y', 'Z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('V(m/sec)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/missle_V','-depsc');
else
    fprintf("Ooooooops\n")
end

%% Target %%

% state %
set(gca, 'FontSize', 16)
plot(simulation_data.target_state, 'linewidth', 2);
legend('X', 'Y', 'Z', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('State(m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/target_state','-depsc');
else
    fprintf("Ooooooops\n")
end

% attitude %
set(gca, 'FontSize', 16)
plot(simulation_data.target_attitude, 'linewidth', 2);
legend('\theta', '\psi', 'Location','southwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Attitude(deg)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/target_attitude','-depsc');
else
    fprintf("Ooooooops\n")
end

% Velocity %
set(gca, 'FontSize', 16)
plot(simulation_data.V_target, 'linewidth', 2);
% legend('X', 'Y', 'Z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('V(m/sec)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/target_V','-depsc');
else
    fprintf("Ooooooops\n")
end

%% missle vs target %%

% state %
f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
plot(simulation_data.missle_state, 'linewidth', 2);
hold on;
plot(simulation_data.target_state, '--', 'linewidth', 2);
legend('X_m', 'Y_m', 'Z_m', 'X_t', 'Y_t', 'Z_t',...
    'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('State(m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
set(gca, 'FontSize', 16)
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/missle_vs_target_state','-depsc');
else
    fprintf("Ooooooops\n")
end
close;
%% 3D %%

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
x_m = simulation_data.missle_state.Data(1, 1, :);
x_m = reshape(x_m, [length(x_m), 1]);
y_m = simulation_data.missle_state.Data(2, 1, :);
y_m = reshape(y_m, [length(y_m), 1]);
z_m = simulation_data.missle_state.Data(3, 1, :);
z_m = reshape(z_m, [length(z_m), 1]);


x_t = simulation_data.target_state.Data(1, 1, :);
x_t = reshape(x_t, [1, length(x_t)]);
y_t = simulation_data.target_state.Data(2, 1, :);
y_t = reshape(y_t, [1, length(y_t)]);
z_t = simulation_data.target_state.Data(3, 1, :);
z_t = reshape(z_t, [1, length(z_t)]);
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
title('');
set(gca, 'FontSize', 16)
% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/3DoF_missle_vs_target_state','-depsc');
else
    fprintf("Ooooooops\n")
end


%% missle vs target maneuver %%
% run manuver %
load('18-Apr-2023-17-02-23-answer.mat');
[~, time] = miss_distance_time_calculator(attitude);
modelname = "maneuver_b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn, 'attitude_m0', attitude*pi/180);
simIn = setVariable(simIn, 'final_time', time);

simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance.Data);

fprintf("miss distance anfer manuver: %.4f\n", miss_distance);

% state %
f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
plot(simulation_data.missle_state, 'linewidth', 2);
hold on;
plot(simulation_data.target_state, '--', 'linewidth', 2);
legend('X_m', 'Y_m', 'Z_m', 'X_t', 'Y_t', 'Z_t',...
    'Location','southeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('State(m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
set(gca, 'FontSize', 16)
axis tight
xlim([8, simulation_data.missle_state.Time(end)])
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/missle_vs_target_state_maneuver','-depsc');
else
    fprintf("Ooooooops\n")
end
close;
%% 3D maneuver %%

f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
x_m = simulation_data.missle_state.Data(1, 1, :);
x_m = reshape(x_m, [length(x_m), 1]);
y_m = simulation_data.missle_state.Data(2, 1, :);
y_m = reshape(y_m, [length(y_m), 1]);
z_m = simulation_data.missle_state.Data(3, 1, :);
z_m = reshape(z_m, [length(z_m), 1]);


x_t = simulation_data.target_state.Data(1, 1, :);
x_t = reshape(x_t, [1, length(x_t)]);
y_t = simulation_data.target_state.Data(2, 1, :);
y_t = reshape(y_t, [1, length(y_t)]);
z_t = simulation_data.target_state.Data(3, 1, :);
z_t = reshape(z_t, [1, length(z_t)]);
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
title('');
set(gca, 'FontSize', 16)
% axis tight
[dir_state, ~, ~] = mkdir('../../Figure/b');
if dir_state
    print('../../Figure/b/3DoF_missle_vs_target_state_maneuver','-depsc');
else
    fprintf("Ooooooops\n")
end