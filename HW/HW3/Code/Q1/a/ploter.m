%% ploter %%
clear;
clc;
%% section I %%
load('18-May-2023-16-56-22-answer.mat');
attitude = attitude*pi/180;
theta_m0 = attitude(1);
psi_m0 = attitude(2);
attitude_m0 = [theta_m0; psi_m0];
init_I;
% transfer matrix %
T_VG_m = [cos(theta_m0)*cos(psi_m0)   cos(theta_m0)*sin(psi_m0)   sin(theta_m0)
            -sin(psi_m0)               cos(psi_m0)            0
        -sin(theta_m0)*cos(psi_m0)  -sin(theta_m0)*sin(psi_m0)    cos(theta_m0)];

% transformation %
d_state_m = T_VG_m'*[V_m0;0;0;];
simulation_a_I = sim('a_I');

%% prosessing data %%
x_missle = simulation_a_I.enviroment.missle.missle_state.Data(1, :, :);
x_missle = reshape(x_missle, [1, length(x_missle)]);

y_missle = simulation_a_I.enviroment.missle.missle_state.Data(2, :, :);
y_missle = reshape(y_missle, [1, length(y_missle)]);

z_missle = simulation_a_I.enviroment.missle.missle_state.Data(3, :, :);
z_missle = reshape(z_missle, [1, length(z_missle)]);

x_target = simulation_a_I.enviroment.target.target_state.Data(1, :, :);
x_target = reshape(x_target, [1, length(x_target)]);

y_target = simulation_a_I.enviroment.target.target_state.Data(2, :, :);
y_target = reshape(y_target, [1, length(y_target)]);

z_target = simulation_a_I.enviroment.target.target_state.Data(3, :, :);
z_target = reshape(z_target, [1, length(z_target)]);

%% plot %%

% 3d %
f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
set(gca, 'FontSize', 16)
plot3(x_target, y_target, z_target, 'b', 'LineWidth', 2);
hold on
plot3(x_missle, y_missle, z_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/a');
if dir_state
    print('../../../Figure/Q1/a/collision_course','-depsc');
else
    fprintf("Ooooooops\n")
end
close;

% xy plane %
set(gca, 'FontSize', 16)
plot(x_target, y_target, 'b', 'LineWidth', 2);
hold on;
plot(x_missle, y_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
if dir_state
    print('../../../Figure/Q1/a/xy_sec_I','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;
% xz plane %
set(gca, 'FontSize', 16)
plot(x_target, z_target, 'b', 'LineWidth', 2);
hold on;
plot(x_missle, z_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
if dir_state
    print('../../../Figure/Q1/a/xz_sec_I','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;

% yz plane %
set(gca, 'FontSize', 16)
plot(y_target, z_target, 'b', 'LineWidth', 2);
hold on;
plot(y_missle, z_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
if dir_state
    print('../../../Figure/Q1/a/yz_sec_I','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;

%% section II %%
simulation_a_II = sim('a_II');

%% prosessing data %%
x_missle = simulation_a_II.enviroment.missle.missle_state.Data(1, :, :);
x_missle = reshape(x_missle, [1, length(x_missle)]);
y_missle = simulation_a_II.enviroment.missle.missle_state.Data(2, :, :);
y_missle = reshape(y_missle, [1, length(y_missle)]);
z_missle = simulation_a_II.enviroment.missle.missle_state.Data(3, :, :);
z_missle = reshape(z_missle, [1, length(z_missle)]);
x_target = simulation_a_II.enviroment.target.target_state.Data(1, :, :);
x_target = reshape(x_target, [1, length(x_target)]);
y_target = simulation_a_II.enviroment.target.target_state.Data(2, :, :);
y_target = reshape(y_target, [1, length(y_target)]);
z_target = simulation_a_II.enviroment.target.target_state.Data(3, :, :);
z_target = reshape(z_target, [1, length(z_target)]);

%% plot %%
% 3d %
f = figure;
width=1440;
height=900;
f.Position = [15 15 width height];
set(gca, 'FontSize', 16)
plot3(x_target, y_target, z_target, 'b', 'LineWidth', 2);
hold on
plot3(x_missle, y_missle, z_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
zlabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/a');
if dir_state
    print('../../../Figure/Q1/a/collision_course','-depsc');
else
    fprintf("Ooooooops\n")
end

close;

% xy plane %
set(gca, 'FontSize', 16)
plot(x_target, y_target, 'b', 'LineWidth', 2);
hold on;
plot(x_missle, y_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
if dir_state
    print('../../../Figure/Q1/a/xy_sec_II','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;
% xz plane %
set(gca, 'FontSize', 16)
plot(x_target, z_target, 'b', 'LineWidth', 2);
hold on;
plot(x_missle, z_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
if dir_state
    print('../../../Figure/Q1/a/xz_sec_II','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;

% yz plane %
set(gca, 'FontSize', 16)
plot(y_target, z_target, 'b', 'LineWidth', 2);
hold on;
plot(y_missle, z_missle, '--r', 'LineWidth', 2);
legend('target', 'missle', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Z(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
if dir_state
    print('../../../Figure/Q1/a/yz_sec_II','-depsc');
else
    fprintf("Ooooooops\n")
end
hold off;