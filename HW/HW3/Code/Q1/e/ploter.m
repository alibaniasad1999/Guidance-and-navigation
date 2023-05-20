load('MD_CE_R_min_vary.mat')
set(gca, 'FontSize', 16)
plot(R_min, MD, 'b', 'LineWidth', 2);
xlabel('$R_{\min}$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/e');
if dir_state
    print('../../../Figure/Q1/e/MD','-depsc');
else
    fprintf("Ooooooops\n")
end
