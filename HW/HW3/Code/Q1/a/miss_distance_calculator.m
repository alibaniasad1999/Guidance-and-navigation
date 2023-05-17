function miss_distance = miss_distance_calculator(attitude)

attitude_m0 = attitude*pi/180;
theta_m0 = attitude_m0(1);
psi_m0 = attitude_m0(2);
init_I; % run init script
% transfer matrix %
T_VG_m = [cos(theta_m0)*cos(psi_m0)   cos(theta_m0)*sin(psi_m0)   sin(theta_m0)
            -sin(psi_m0)               cos(psi_m0)            0
        -sin(theta_m0)*cos(psi_m0)  -sin(theta_m0)*sin(psi_m0)    cos(theta_m0)];

% transformation %
d_state_m = T_VG_m'*[V_m0;0;0;]; 

modelname = "a_I";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'attitude_m0',attitude*pi/180);
simIn = setVariable(simIn,'theta_m0',theta_m0*pi/180);
simIn = setVariable(simIn,'psi_m0',psi_m0*pi/180);
simIn = setVariable(simIn,'d_state_m',d_state_m);

simulation_data = sim(simIn);

miss_distance = min(simulation_data.distance.Data);

fprintf("with theta: %.4f and psi: %.4f, miss distance is: %.4f\n", ...
    attitude(1), attitude(2), miss_distance);