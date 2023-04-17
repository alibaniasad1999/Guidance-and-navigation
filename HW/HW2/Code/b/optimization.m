clear;
clc;
%% optimization %%

% genetic algorithm optimization %

x = fsolve(@miss_distance_calculator,[0, 0]);


fprintf("miss distance with theta_0=%.2f and psi_0=%.2f is %.4f m\n", ...
    [x(1), x(2), miss_distance_calculator(x)])

%% save data %%

now_time = string(datetime('now'));
str_now_time = now_time{1};
str_now_time(12) = '-';
str_now_time(15) = '-';
str_now_time(18) = '-';
save(append(str_now_time, '-',...
    'ga_answer'), 'x');