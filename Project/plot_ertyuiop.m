% x = position_array(1, 1, :);
% y = position_array(2, 1, :);
% % z = position_array(3, 1, :);
% x = reshape(x, 1, length(x));
% y = reshape(y, 1, length(y));
% % z = reshape(z, 1, length(z));
% 
% 
% % z1 = position_array(3, 2, :);
% x1 = reshape(x1, 1, length(x));
% y1 = reshape(y1, 1, length(y));
% % z1 = reshape(z1, 1, length(z));
% 
% x2 = position_array(1, 3, :);
% y2 = position_array(2, 3, :);
% % z2 = position_array(3, 3, :);
% x2 = reshape(x2, 1, length(x));
% y2 = reshape(y2, 1, length(y));
% % z2 = reshape(z2, 1, length(z));

% plot(x, y);
% hold on
% plot(x1, y1);
% plot(x2, y2);

for i=1:1
    plot(reshape(position_array(1, i, :), 1, length(position_array)),...
         reshape(position_array(2, i, :), 1, length(position_array)));
    hold on
end


