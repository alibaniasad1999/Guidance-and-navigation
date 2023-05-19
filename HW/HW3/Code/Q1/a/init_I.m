%% init data %%
% global %
g = 9.81;
% missile %
x_m0 = 0;
y_m0 = 0;
z_m0 = 0;
state_m0 = [x_m0; y_m0; z_m0];
% theta_m0 = 0;
% psi_m0 = 0;
% attitude_m0 = [theta_m0; psi_m0];
V_m0 = 200; % m/s
% target %
x_t0 = 12000; % m/s
y_t0 = 0;
z_t0 = 3000; % m/s
state_t0 = [x_t0; y_t0; z_t0];
V_t0 = 300; % m/s good is 106.9
theta_t0 = 0;
psi_t0 = 130/pi*180;
attitude_t0 = [theta_t0; psi_t0];


% transfer matrix %
T_VG_t = [cos(theta_t0)*cos(psi_t0)   cos(theta_t0)*sin(psi_t0)   sin(theta_t0)
            -sin(psi_t0)               cos(psi_t0)            0
        -sin(theta_t0)*cos(psi_t0)  -sin(theta_t0)*sin(psi_t0)    cos(theta_t0)];

d_state_t = T_VG_t'*[V_t0;0;0;]; 
