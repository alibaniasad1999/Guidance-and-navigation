function [position_array, velocity_array] = simulation_function(x_arena, spheres, ...
    agent_number, radius, time, dt)
    n = agent_number*2;
    position = rand(1,n)*200-100;
    velocity = ones(1,n);
    %% example of use of the function %%
    position_array = zeros(2,n/2,time/dt);
    velocity_array = zeros(2,n/2,time/dt);
    for i = 1:time/dt
        v_command = VasarhelyiGuidanceLaw(position, velocity,...
            x_arena, spheres, radius, dt);
        position = position + v_command * dt;
        position_array(:, :, i) = reshape(position, 2, n/2);
        velocity_array(:, :, i) = reshape(v_command, 2, n/2);
        velocity = v_command;
    end
end

