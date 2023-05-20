load('MD_CE_T_vary.mat')
set(gca, 'FontSize', 16)
plot(T, MD, 'b', 'LineWidth', 2);
xlabel('T(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/c');
if dir_state
    print('../../../Figure/Q1/c/MD','-depsc');
else
    fprintf("Ooooooops\n")
end

set(gca, 'FontSize', 16)
plot(T, CE, 'b', 'LineWidth', 2);
xlabel('T(Second)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Control Effort', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

if dir_state
    print('../../../Figure/Q1/c/CE','-depsc');
else
    fprintf("Ooooooops\n")
end

