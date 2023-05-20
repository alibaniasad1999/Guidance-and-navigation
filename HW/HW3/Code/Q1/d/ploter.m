load('MD_CE_saturation_vary.mat')
set(gca, 'FontSize', 16)
plot(saturation_lim, MD, 'b', 'LineWidth', 2);
xlabel('g(m/$\sec$)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/d');
if dir_state
    print('../../../Figure/Q1/d/MD','-depsc');
else
    fprintf("Ooooooops\n")
end

set(gca, 'FontSize', 16)
plot(saturation_lim, CE, 'b', 'LineWidth', 2);
xlabel('g(m/$\sec$)', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Control Effort', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

if dir_state
    print('../../../Figure/Q1/d/CE','-depsc');
else
    fprintf("Ooooooops\n")
end

