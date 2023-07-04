clear;
clc;
%%%%%%%% test Vasarhelyi Guidance Law %%%%%%%%
agent_number = 10;
n = agent_number*2;
position = rand(1,n)*200-100;
velocity = zeros(1,n);


dt = 0.01;
%% example of use of the function %%
position_array = zeros(2,n/2,1000);
for i = 1:1000
    v_command = VasarhelyiGuidanceLaw(position, velocity, dt);
    position = position + v_command * dt;
    position_array(:, :, i) = reshape(position, 2, n/2);
    velocity = v_command;
end
plot_results;