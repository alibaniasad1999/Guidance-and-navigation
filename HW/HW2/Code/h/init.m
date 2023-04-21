%% init data %%
% missile %
x_m0 = 0;
y_m0 = 0;
z_m0 = 0;
state_m0 = [x_m0; y_m0; z_m0];
V_m0 = 100; % m/s
theta_m0 = 20*pi/180;
psi_m0 = 0;
attitude_m0 = [theta_m0; psi_m0];
% target %
x_t0 = 8000; % m/s
y_t0 = 0;
z_t0 = 3000; % m/s
state_t0 = [x_t0; y_t0; z_t0];
V_t0 = 300; % m/s good is 106.9
theta_t0 = 0;
psi_t0 = pi;
attitude_t0 = [theta_t0; psi_t0];

% transfer matrix %
T_VG_m = [cos(theta_m0)*cos(psi_m0)   cos(theta_m0)*sin(psi_m0)   sin(theta_m0)
            -sin(psi_m0)               cos(psi_m0)            0
        -sin(theta_m0)*cos(psi_m0)  -sin(theta_m0)*sin(psi_m0)    cos(theta_m0)];

% transformation %
d_state_m = T_VG_m'*[V_m0;0;0;]; 

% transfer matrix %
T_VG_t = [cos(theta_t0)*cos(psi_t0)   cos(theta_t0)*sin(psi_t0)   sin(theta_t0)
            -sin(psi_t0)               cos(psi_t0)            0
        -sin(theta_t0)*cos(psi_t0)  -sin(theta_t0)*sin(psi_t0)    cos(theta_t0)];

d_state_t = T_VG_t'*[V_t0;0;0;]; 

% theta_t0_new_init = 0;
% psi_t0_new_init = 0;
% attitude_t0_new_init = [theta_t0_new_init; psi_t0_new_init];
% 
% % transfer matrix %
% T_VG_t_new_init = [cos(theta_t0_new_init)*cos(psi_t0_new_init)   cos(theta_t0_new_init)*sin(psi_t0_new_init)   sin(theta_t0_new_init)
%             -sin(psi_t0_new_init)               cos(psi_t0_new_init)            0
%         -sin(theta_t0_new_init)*cos(psi_t0_new_init)  -sin(theta_t0_new_init)*sin(psi_t0_new_init)    cos(theta_t0_new_init)];
% 
% d_state_t_new_init = T_VG_t_new_init'*[V_t0;0;0;]; 


load('../c/19-Apr-2023-15-45-38-answer.mat');
K_epsilon = k_LOS(1);
k_sigma = k_LOS(2);

