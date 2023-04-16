%% optimization %%
init; % run init script

modelname = "b";
simIn = Simulink.SimulationInput(modelname);
simIn = setVariable(simIn,'theta_m0',2); % ,'theta_m0', 2
sim(simIn);