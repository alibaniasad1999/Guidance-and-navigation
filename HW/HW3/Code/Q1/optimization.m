clear;
clc;
%% optimization %%

attitude = fsolve(@miss_distance_calculator,[0, 0]);


fprintf("miss distance with theta_0=%.2f and psi_0=%.2f is %.4f m\n", ...
    [attitude(1), attitude(2), miss_distance_calculator(attitude)])

%% save data %%

now_time = string(datetime('now'));
str_now_time = now_time{1};
str_now_time(12) = '-';
str_now_time(15) = '-';
str_now_time(18) = '-';
save(append(str_now_time, '-',...
    'answer'), 'attitude');