function plot_results_timeline(agent_number, position_array, velocity_array, x_arena, spheres)
dt = 0.1;
for i=1:length(position_array)
    x = reshape(position_array(1, :, i), 1, agent_number);
    y = reshape(position_array(2, :, i), 1, agent_number);
    v = reshape(velocity_array(:, :, i), 2, agent_number);
    scatter(x,y, 1, sum(v))
    hold on
    axis([-100 100, -100 100])
            xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
        ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
        set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
        if i == 1
            title(append('Time: ', string(0)), 'Interpreter','latex')
        else
            title(append('Time: ', string(i*dt)), 'Interpreter','latex')
        end
        print(append('../../../../Figure/MIL/time_line/', string(i)), '-dpng');
        axis tight
axis equal
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
end
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
axis tight
axis equal
end

function plot_circle(x, y, r)
% plot circle with x, y, and raduis
th = 0:pi/50:2*pi;
xunit = r * cos(th) + x;
yunit = r * sin(th) + y;
plot(xunit, yunit, 'k', 'LineWidth',2);
end



