clear;
clc;
%% ploter %%
load('MD_LA_vary.mat')
LA = 20:5:80;
set(gca, 'FontSize', 16)
plot(LA, MD, 'b', 'LineWidth', 2);
xlabel('Look Angle$(\deg)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Miss Distance(m)', 'interpreter', 'latex', 'FontSize', 24);
axis tight
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');

[dir_state, ~, ~] = mkdir('../../../Figure/Q1/f');
if dir_state
    print('../../../Figure/Q1/f/MD','-depsc');
else
    fprintf("Ooooooops\n")
end
