clc
clear
%% Question 3 %%

% data
gps_1 = [8.27, -6.23, 16.74]*1e6; % km
t_1 = 8.12; % second

gps_2 = [18.41, 9.21, -6.23]*1e6; % km
t_2 = 7.05; % second

gps_3 = [16.94, -11.75, -5.25]*1e6; % km
t_3 = 7.36; % second

gps_4 = [0.15, 1.35, -19.18]*1e6; % km
t_4 = 6.64; % second

% light speed

c = 3e8; % m/s
c = c/1000; % km/s

% data processing
x_gps = [gps_1(1); gps_2(1); gps_3(1); gps_4(1)];
y_gps = [gps_1(2); gps_2(2); gps_3(2); gps_4(2)];
z_gps = [gps_1(3); gps_2(3); gps_3(3); gps_4(3)];
t_gps = [t_1; t_2; t_3; t_4];

% solve with matlab built-in function
x = sym('x', 'real');
y = sym('y', 'real');
z = sym('z', 'real');
d = sym('d', 'real');

eq = (x_gps - x).^2 + (y_gps - y).^2 + (z_gps - z).^2 - (c*(t_gps - d)).^2 ...
    == 0;

