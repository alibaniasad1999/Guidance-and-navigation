x = position_array(1, 1, :);
y = position_array(2, 1, :);
z = position_array(3, 1, :);
x = reshape(x, 1, length(x));
y = reshape(y, 1, length(y));
z = reshape(z, 1, length(z));

x1 = position_array(1, 2, :);
y1 = position_array(2, 2, :);
z1 = position_array(3, 2, :);
x1 = reshape(x1, 1, length(x));
y1 = reshape(y1, 1, length(y));
z1 = reshape(z1, 1, length(z));

x2 = position_array(1, 3, :);
y2 = position_array(2, 3, :);
z2 = position_array(3, 3, :);
x2 = reshape(x2, 1, length(x));
y2 = reshape(y2, 1, length(y));
z2 = reshape(z2, 1, length(z));

plot3(x, y, z);
hold on
plot3(x1, y1, z1);
plot3(x2, y2, z2);


