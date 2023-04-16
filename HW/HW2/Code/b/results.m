clear;
clc;
% resulst %
%% missle %%
out = sim("a.slx");
% state %
set(gca, 'FontSize', 16)
plot(out.missle_state, 'linewidth', 2);
legend('X', 'Y', 'Z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('State(m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
[dir_state, ~, ~] = mkdir('../../Figure/a');
if dir_state
    print('../../Figure/a/missle_state','-depsc');
else
    fprintf("Ooooooops\n")
end

% attitude %
set(gca, 'FontSize', 16)
plot(out.missle_attitude, 'linewidth', 2);
legend('\theta', '\psi', 'Location','southwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Attitude(deg)', 'interpreter', 'latex', 'FontSize', 24);
title('');
[dir_state, ~, ~] = mkdir('../../Figure/a');
if dir_state
    print('../../Figure/a/missle_attitude','-depsc');
else
    fprintf("Ooooooops\n")
end

% Velocity %
set(gca, 'FontSize', 16)
plot(out.V_missle, 'linewidth', 2);
% legend('X', 'Y', 'Z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('V(m/sec)', 'interpreter', 'latex', 'FontSize', 24);
title('');
[dir_state, ~, ~] = mkdir('../../Figure/a');
if dir_state
    print('../../Figure/a/missle_V','-depsc');
else
    fprintf("Ooooooops\n")
end

%% Target %%

% state %
set(gca, 'FontSize', 16)
plot(out.target_state, 'linewidth', 2);
legend('X', 'Y', 'Z', 'Location','northeast', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('State(m)', 'interpreter', 'latex', 'FontSize', 24);
title('');
[dir_state, ~, ~] = mkdir('../../Figure/a');
if dir_state
    print('../../Figure/a/target_state','-depsc');
else
    fprintf("Ooooooops\n")
end

% attitude %
set(gca, 'FontSize', 16)
plot(out.target_attitude, 'linewidth', 2);
legend('\theta', '\psi', 'Location','southwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('Attitude(deg)', 'interpreter', 'latex', 'FontSize', 24);
title('');
[dir_state, ~, ~] = mkdir('../../Figure/a');
if dir_state
    print('../../Figure/a/target_attitude','-depsc');
else
    fprintf("Ooooooops\n")
end

% Velocity %
set(gca, 'FontSize', 16)
plot(out.V_target, 'linewidth', 2);
% legend('X', 'Y', 'Z', 'Location','northwest', 'FontSize', 20);
set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
xlabel('time($\sec)$', 'interpreter', 'latex', 'FontSize', 24);
ylabel('V(m/sec)', 'interpreter', 'latex', 'FontSize', 24);
title('');
[dir_state, ~, ~] = mkdir('../../Figure/a');
if dir_state
    print('../../Figure/a/target_V','-depsc');
else
    fprintf("Ooooooops\n")
end

