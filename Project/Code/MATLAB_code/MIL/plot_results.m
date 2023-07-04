
for i=1:10
    plot(reshape(position_array(1, i, :), 1, length(position_array)),...
         reshape(position_array(2, i, :), 1, length(position_array)));
    hold on
end


