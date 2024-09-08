eps = 1e-6;
count_iter = 100000;

% приведение к виду 3.2
% tg(3x - 0.5) + xy = 1.5

% приведение к виду 3.2
% y^2 - sin(x + 1) = 2
% y = sqrt(2 + sin(x+1))

% начальные приближения
x = 0.3;
y = 1.6;

for i = 1:count_iter
    x1 = (atan(1.5 - x*y) + 0.5) / 3;
    y1 = sqrt(2 + sin(x+1));
    if max(abs([x1 - x, y1 - y])) < eps
        break;
    end
    x = x1;
    y = y1;
end
fprintf('Метод простой итерации\n')
fprintf('Решение: (%f, %f)\n', x, y)
