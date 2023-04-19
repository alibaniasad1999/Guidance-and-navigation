clear;
clc;
% resulst %
%% missle %%
load('19-Apr-2023-15-45-38-answer.mat');
modelname = "c";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'K_epsilon',k_LOS(1));
simIn = setVariable(simIn,'k_sigma',k_LOS(2));
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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/missle_state','-depsc');
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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/missle_attitude','-depsc');
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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/missle_V','-depsc');
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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/target_state','-depsc');
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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/target_attitude','-depsc');
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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/target_V','-depsc');
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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/missle_vs_target_state','-depsc');
else
    fprintf("Ooooooops\n")
end
close;
%% 3D %%

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
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/3DoF_missle_vs_target_state','-depsc');
else
    fprintf("Ooooooops\n")
end
close
%% command %%

set(gca, 'FontSize', 16)
plot(simulation_data.command, 'linewidth', 2);
legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a (m/$\sec^2$)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/command','-depsc');
else
    fprintf("Ooooooops\n")
end

%% miss distance history %%

set(gca, 'FontSize', 16)
plot(simulation_data.miss_distance, 'linewidth', 2);
% legend('a_y', 'a_z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance (m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
axis tight
[dir_state, ~, ~] = mkdir('../../Figure/c');
if dir_state
    print('../../Figure/c/miss_distance','-depsc');
else
    fprintf("Ooooooops\n")
end

