clc
clear
%% Part I %%

% data
gps_1 = [8.27, -6.23, 16.74]*1e6; % km
t_1 = 8.12; % second

gps_2 = [18.41, 9.21, -6.23]*1e6; % km
t_2 = 7.05; % second

gps_3 = [16.94, -11.75, -5.25]*1e6; % km
t_3 = 7.36; % second

gps_4 = [0.15, 1.35, -19.18]*1e6; % km
t_4 = 6.64; % second

% light speed

c = 3e8; % m/s
c = c/1000; % km/s

% data processing
x_gps = [gps_1(1); gps_2(1); gps_3(1); gps_4(1)];
y_gps = [gps_1(2); gps_2(2); gps_3(2); gps_4(2)];
z_gps = [gps_1(3); gps_2(3); gps_3(3); gps_4(3)];
t_gps = [t_1; t_2; t_3; t_4];

% solve with matlab built-in function
x = sym('x', 'real');
y = sym('y', 'real');
z = sym('z', 'real');
d = sym('d', 'real');

eq = (x_gps - x).^2 + (y_gps - y).^2 + (z_gps - z).^2 - (c*(t_gps - d)).^2 ...
    == 0;

gps_ans = vpasolve(eq);

x_ans = gps_ans.x;
y_ans = gps_ans.y;
z_ans = gps_ans.z;
d_ans = gps_ans.d;

for i = 1:length(x)
    fprintf("%d conition x=%.2f, y=%.2f, z=%.2f\n",...
        i, x_ans(i), y_ans(i), z_ans(i))
end

%% latex table version %%
for i = 1:length(x_ans)
    fprintf("\\lr{%.2f} & \\lr{%.2f} & \\lr{%.2f} & \\lr{%.2f} & \\lr{%d}\\\\\n",...
        d_ans(i), z_ans(i), y_ans(i), x_ans(i), i)
end

%% part II %% calculate all permutation

eq = subs(eq, d, 0.05);
all_eq = nchoosek(eq, 3);

for i = 1:length(all_eq)
    ans_gps = vpasolve(all_eq(i));
    fprintf("%d conition x=%.2f, y=%.2f, z=%.2f\n", i, ans_gps.x, ans_gps.y,...
        ans_gps.z)
    if isempty(ans_gps.x)
        fprintf('no valid answer\n');
    end
end


%% location error %%
t_c = 80 / 1000 / c;


