function plot_results(x_arena, spheres)
for i=1:agent_number
    plot(reshape(position_array(1, i, :), 1, length(position_array)),...
         reshape(position_array(2, i, :), 1, length(position_array)));
    hold on
end



