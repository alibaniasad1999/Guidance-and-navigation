clear;
clc;
%% optimization %%

options = optimoptions('particleswarm','SwarmSize',20,'HybridFcn',@fmincon);

k_LOS = particleswarm(@miss_distance_calculator, 2,...
    [10; 10],[100; 100], options);

fprintf("epsilon gain is: %.4f and sigma gain is: %.4f and miss distance " + ...
    "%.4f \n", ...
    [k_LOS(1), k_LOS(2), miss_distance_calculator(k_LOS)]);

%% save data %%

now_time = string(datetime('now'));
str_now_time = now_time{1};
str_now_time(12) = '-';
str_now_time(15) = '-';
str_now_time(18) = '-';
save(append(str_now_time, '-',...
    'answer'), 'k_LOS');