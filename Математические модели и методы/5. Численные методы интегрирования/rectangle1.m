a = 0;
b = pi;
n = 1000;
h = (b-a)/n;
s_left = 0;
s_mid = 0;
s_right = 0;
for i = 0:n-1
    xi = h*i;
    xi1 = h*(i+1);
    s_left = s_left + h * func(xi);
    s_mid = s_mid + h * func((xi + xi1) / 2);
    s_right = s_right + h * func(xi1);
end
fprintf('Метод прямоугольников\nexp(x).*sin(x)\n\n');
fprintf('Левые прямоугольники I- =\t%f\n', s_left);
fprintf('Средние прямоугольники I =\t%f\n', s_mid);
fprintf('Правые прямоугольники I+ =\t%f\n\n', s_right);
x = a:1/10000:b;
y = exp(x).*sin(x);
accur = trapz(x, y);
fprintf('Точное значение = %f\n\n', accur);
fprintf('Ошибка I- =\t%f\n', s_left - accur);
fprintf('Ошибка I =\t%f\n', s_mid - accur);
fprintf('Ошибка I+ =\t%f\n', s_right - accur);

function resultf = func(x) 
    resultf = exp(x).*sin(x);
end