clear;
clc;
%% run simulink %%
out = sim("a");
x_ref = 0:1:30000;
y_ref = 0.5 * x_ref;
%% plot %%
set(gca, 'FontSize', 16)
plot(x_ref,y_ref...
    , '--k', 'LineWidth', 2);
hold on
plot(out.X_u.signals.values(:,1),out.X_u.signals.values(:,2),'LineWidth',2)
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend('refrence', 'UAV', 'Location','northwest', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/a');
if dir_state
    print('../../../Figure/Q2/a/xy', '-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
% acceleration %
set(gca, 'FontSize', 16)
plot(out.tout, out.a_u.signals.values...
    , 'b', 'LineWidth', 2);
xlabel('Time(sec)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a$_{\textrm{command}}$(m/sec$^2$)',...
    'interpreter', 'latex', 'FontSize', 24);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/a');
if dir_state
    print('../../../Figure/Q2/a/acc', '-depsc');
else
    fprintf("Ooooooops\n")
end
