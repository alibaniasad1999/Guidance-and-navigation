load('MD_delta_guidance_t_vary.mat')
set(gca, 'FontSize', 16)
plot(delta_guidance_t, MD, 'b', 'LineWidth', 2);
xlabel('Zero Order Hold$(\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance(m)', 'interpreter', 'latex', 'FontSize', 24);
% axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/h');
if dir_state
    print('../../../Figure/Q1/h/MD','-depsc');
else
    fprintf("Ooooooops\n")
end
