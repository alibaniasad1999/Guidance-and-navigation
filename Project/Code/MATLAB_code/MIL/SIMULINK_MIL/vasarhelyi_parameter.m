%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Vasarhelyi Paramteres
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Repulsion

% Repulsion range
r0_rep = d_ref; % radius of repulsion
% Repulsion gain
p_rep = 0.3;


%% Friction

% Stopping point offset of alignment
r0_fric = 85.3;
% Coefficient of velocity alignment
C_fric = 0.05;
% Velocity slack of alignement
v_fric = 0.63;
% Gain of braking curve
p_fric = 3.2;
% Acceleration of braking curve
a_fric = 4.16;


%% Obstacles and wall parameters

% Stopping point offset of walls
r0_shill = 0.1;
% Velocity of virtual shill agents
v_shill = 1.6;
% Gain of bracking curve for walls
p_shill = 0.55;
% Acceleration of braking curve for walls
a_shill = 3.02;    