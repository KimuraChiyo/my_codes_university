eps = 1e-6;
count_iter = 100000;
% tg(3x-0.5) + xy = 1.5
% F(x,y) = 0
% tg(3x-0.5) + xy - 1.5 = 0
% произв по икс
% 3 / cos^2(3x - 0.5) + y
% произв по игрек
% x


% y^2 - sin(x + 1) = 2
% G(x,y) = 0
% y^2 - sin(x + 1) - 2 = 0
% произв по икс
% -cos(x + 1)
% произв по игрек
% 2y

x = 0.4;
y = 1.6;

for i = 1:count_iter
    x1 = x - 1/jacobi(x, y) * det([F(x, y), x; G(x, y), 2*y]);
    y1 = y - 1/jacobi(x, y) * det([3/(cos(3*x-0.5)*cos(3*x-0.5)), F(x, y); -cos(x+1), G(x, y)]);
    if max(abs([x1 - x, y1 - y])) < eps
        break;
    end
    x = x1;
    y = y1;
end
fprintf('Метод Ньютона\n')
fprintf('Решение: (%f, %f)\n', x, y)

function resultf = F(x, y)
    resultf = tan(3*x - 0.5) + x*y - 1.5;
end
function resultg = G(x, y)
    resultg = y*y - sin(x + 1) - 2;
end
function jacobi = jacobi(x, y)
    jacobi = det([3/(cos(3*x-0.5)*cos(3*x-0.5)), x; -cos(x+1), 2*y]);
end