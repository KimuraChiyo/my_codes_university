a = 0;
b = 0.9;
n = 18;
h = (b-a)/n;
s = 0;
for i = 0:n
    xi = h*i;
    if i == 0 | i == n
        s = s + (h / 3) * func(xi);
        continue;
    end
    if mod(i, 2) == 1
        s = s + (h / 3) * 4 * func(xi);
        continue;
    end
    if mod(i, 2) == 0
        s = s + (h / 3) * 2 * func(xi);
        continue;
    end
end

fprintf('Метод Симпсона\nx/sqrt(1-x^2)\n\n');
fprintf('S = %.9f\n\n', s);
fprintf('Точное значение =\t%.9f\n\n', accur(a, b));
fprintf('Ошибка I = %.9f\n', s - accur(a,b))

function resultp = prim(x)
    resultp = -sqrt(1 - x*x);
    % resultp = -cos(x);
end
function resultf = func(x) 
    resultf = x / sqrt(1 - x*x);
    % resultf = sin(x);
end
function resulta = accur(a, b)
    resulta = prim(b) - prim(a);
end