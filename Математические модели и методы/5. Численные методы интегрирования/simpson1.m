a = 0;
b = pi;
n = 1000;
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

fprintf('Метод Симпсона\nexp(x).*sin(x)\n\n');
fprintf('S = %.9f\n\n', s);
x = a:1/10000:b;
y = func(x);
accur = trapz(x, y);
fprintf('Точное значение =\t%.9f\n\n', accur);
fprintf('Ошибка I = %.9f\n', s - accur)

function resultf = func(x) 
    resultf = exp(x).*sin(x);
end