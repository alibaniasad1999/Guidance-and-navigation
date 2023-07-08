function graph_animation_creator_gif(agent_number, position_array, x_arena, spheres,...
    step_time, dt, r)
fig_num = 0;
for i=1:length(position_array)


    if mod(i, floor(step_time/dt)) == 0
        hold off;
        x = position_array(1, :, i);
        y = position_array(2, :, i);
        c = linspace(1,10,agent_number);
        scatter(x, y, [], c, 'filled')
        hold on
    
        % plot x arena square
        plot([x_arena(1), x_arena(1)], [x_arena(2), x_arena(4)], '--k', 'linewidth', 2);
        plot([x_arena(1), x_arena(3)], [x_arena(2), x_arena(2)], '--k', 'linewidth', 2);
        plot([x_arena(3), x_arena(3)], [x_arena(2), x_arena(4)], '--k', 'linewidth', 2);
        plot([x_arena(1), x_arena(3)], [x_arena(4), x_arena(4)], '--k', 'linewidth', 2);
        % plot spheres
        for j=1:length(spheres(1, :))
            % plot circle with x, y, and raduis
            plot_circle(spheres(1, j), spheres(2, j), spheres(3, j));
        end
        % plot graph
        n = length(x);
        
        % Calculate distances between all pairs of particles
        distances = sqrt((x - x').^2 + (y - y').^2);
        
        % Find indices where distance is less than the threshold
        [i_graph, j_graph] = find(distances < r & triu(ones(n)));
        
        % Plot connections between particles
        for k = 1:length(i_graph)
            plot([x(i_graph(k)), x(j_graph(k))], [y(i_graph(k)), y(j_graph(k))], ...
                ':k');
            hold on;
        end
        axis tight
        axis equal
        set(gca, 'FontSize', 16)
 
    xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
    ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
    set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');


    print(append('../../../../Figure/test1/', string(fig_num)), '-dpng');
    fig_num = fig_num + 1;
    end
end
end

function plot_circle(x, y, r)
% plot circle with x, y, and raduis
th = 0:pi/50:2*pi;
xunit = r * cos(th) + x;
yunit = r * sin(th) + y;
plot(xunit, yunit, 'k', 'LineWidth',2);
end



