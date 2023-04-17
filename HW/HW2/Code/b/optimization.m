clear;
clc;
%% optimization %%

% genetic algorithm optimization %

[ga_ans, cost] = ga(@miss_distance_calculator, 2, [], [], [], [],...
    -pi*ones(1, 2), pi*ones(1, 2)); % with -pi:pi bound


fprintf("miss distance with theta_0=%.2f and psi_0=%.2f is %.4f m\n", ...
    [ga_ans(1), ga_ans(2), cost])

%% save data %%

now_time = string(datetime('now'));
str_now_time = now_time{1};
str_now_time(12) = '-';
str_now_time(15) = '-';
str_now_time(18) = '-';
save(append(str_now_time, '-',...
    'ga_answer'), 'ga_ans');