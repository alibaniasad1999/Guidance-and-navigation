clear;
clc;
%% optimization %%

k = fsolve(@miss_distance_calculator,[80, 50]);


fprintf("miss distance with k epsilon=%.2f and k sigma=%.2f is %.4f m in lead angle\n", ...
    [k(1), k(2), miss_distance_calculator(k)])

%% save data %%

now_time = string(datetime('now'));
str_now_time = now_time{1};
str_now_time(12) = '-';
str_now_time(15) = '-';
str_now_time(18) = '-';
save(append(str_now_time, '-',...
    'answer'), 'k');