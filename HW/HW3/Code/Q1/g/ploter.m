load('MD_LOS_rate_vary.mat')
set(gca, 'FontSize', 16)
plot(LOS_rate, MD, 'b', 'LineWidth', 2);
xlabel('Max LOS Rotation$(\deg)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/g');
if dir_state
    print('../../../Figure/Q1/g/MD','-depsc');
else
    fprintf("Ooooooops\n")
end
