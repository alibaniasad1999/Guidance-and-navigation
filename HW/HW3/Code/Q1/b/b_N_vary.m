clear;
clc;
%% calculation of control effort in vary of N parameter %%
all_data = cell(1, 3);
for N = 3:5
    modelname = "b";
    simIn = Simulink.SimulationInput(modelname);
    simIn = setVariable(simIn,'N',N);
    simulation_data = sim(simIn);
    all_data{N-2} = simulation_data;
    ploter;
end
%% all in one %%
for i = 1:length(all_data)
    set(gca, 'FontSize', 16)
    plot(all_data{i}.tout(1:time_index), all_data{i}.guidance_command.Data(1:time_index, 2)...
        , 'LineWidth', 2);
    hold on
    xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
    ylabel('Guidance Command Y axis(m$/\sec^2)$', 'interpreter', 'latex', 'FontSize', 24);
    axis tight
    set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
end
hold off
legend('N=3', 'N=4', 'N=5', 'Location','northwest', 'FontSize', 20);
[dir_state, ~, ~] = mkdir('../../../Figure/Q1/b');
if dir_state
    print('../../../Figure/Q1/b/GC_y','-depsc');
else
    fprintf("Ooooooops\n")
end




for i = 1:length(all_data)
    set(gca, 'FontSize', 16)
    plot(all_data{i}.tout(1:time_index), all_data{i}.guidance_command.Data(1:time_index, 3)...
        , 'LineWidth', 2);
    hold on
    xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
    ylabel('Guidance Command Z axis(m$/\sec^2)$', 'interpreter', 'latex', 'FontSize', 24);
    axis tight
    set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
end
hold off
legend('N=3', 'N=4', 'N=5', 'Location','northwest', 'FontSize', 20);
[dir_state, ~, ~] = mkdir('../../../Figure/Q1/b');
if dir_state
    print('../../../Figure/Q1/b/GC_z','-depsc');
else
    fprintf("Ooooooops\n")
end

for i = 1:length(all_data)
    set(gca, 'FontSize', 16)
    plot(all_data{i}.tout(1:time_index), all_data{i}.Omega.Data(1:time_index, 2)...
        , 'LineWidth', 2);
    xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
    ylabel('$\Omega_y$(rad$/\sec)$', 'interpreter', 'latex', 'FontSize', 24);
    axis tight
    set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
    hold on
end
hold off
legend('N=3', 'N=4', 'N=5', 'Location','northeast', 'FontSize', 20);
if dir_state
    print('../../../Figure/Q1/b/Omega_y', '-depsc');
else
    fprintf("Ooooooops\n")
end


for i = 1:length(all_data)
    set(gca, 'FontSize', 16)
    plot(all_data{i}.tout(1:time_index), all_data{i}.Omega.Data(1:time_index, 3)...
        , 'LineWidth', 2);
    xlabel('Time(Second)', 'interpreter', 'latex', 'FontSize', 24);
    ylabel('$\Omega_z$(rad$/\sec)$', 'interpreter', 'latex', 'FontSize', 24);
    axis tight
    set(gca, 'FontSize', 16, 'FontName', 'Times New Roman');
    hold on
end
hold off
legend('N=3', 'N=4', 'N=5', 'Location','northwest', 'FontSize', 20);
if dir_state
    print('../../../Figure/Q1/b/Omega_z', '-depsc');
else
    fprintf("Ooooooops\n")
end

