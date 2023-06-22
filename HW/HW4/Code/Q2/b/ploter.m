clear;
clc;
%% run simulink %%
L_1_array = 1200:200:3000;
out_array = cell(1, length(L_1_array));
for i = 1:length(L_1_array)
    L_1 = L_1_array(i);
    out_array{i} = sim("b");
end
x_ref = 0:1:30000;
y_ref = 0.5 * x_ref;
%% plot %%
set(gca, 'FontSize', 16)
plot(x_ref,y_ref...
    , '--k', 'LineWidth', 2);
hold on
legend_array = cell(1, length(out_array)+1);
legend_array{1} = 'refrence';
for i = 1:length(out_array)
    out = out_array{i};
    legend_array{i+1} = string(L_1_array(i));
    plot(out.X_u.signals.values(:,1),out.X_u.signals.values(:,2),'LineWidth',2)
end
xlabel('X(m)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Y(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend(legend_array, 'Location','southeast', 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/b');
if dir_state
    print('../../../Figure/Q2/b/xy', '-depsc');
else
    fprintf("Ooooooops\n")
end
hold off
%% acceleration %%
plot_array = cell(1, length(L_1));
set(gca, 'FontSize', 16)
hold on
for i = 1:length(out_array)
    out = out_array{i};
    plot_array{i} =  plot(out.tout, out.a_u.signals.values...
    , 'LineWidth', 2);
end
xlabel('Time(sec)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('a$_{\textrm{command}}$(m/sec$^2$)',...
    'interpreter', 'latex', 'FontSize', 24);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
legend(legend_array{2:end}, 'Location','northeast', 'NumColumns', 2, 'FontSize', 20);

[dir_state, ~, ~] = mkdir('../../../Figure/Q2/b');
if dir_state
    print('../../../Figure/Q2/b/acc', '-depsc');
else
    fprintf("Ooooooops\n")
end
