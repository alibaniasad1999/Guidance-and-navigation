function plot_results(agent_number, position_array, x_arena, spheres)
for i=1:agent_number
    scatter(reshape(position_array(1, i, :), 1, length(position_array)),...
         reshape(position_array(2, i, :), 1, length(position_array)));
    hold on
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



