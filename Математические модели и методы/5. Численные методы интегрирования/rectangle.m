a = 0;
b = 0.9;
n = 18;
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
fprintf('Метод прямоугольников\nx/sqrt(1-x^2)\n\n');
fprintf('Левые прямоугольники I- =\t%f\n', s_left);
fprintf('Средние прямоугольники I =\t%f\n', s_mid);
fprintf('Правые прямоугольники I+ =\t%f\n\n', s_right);
fprintf('Точное значение = %f\n\n', accur(a, b));
fprintf('Ошибка I- =\t%f\n', s_left - accur(a,b))
fprintf('Ошибка I =\t%f\n', s_mid - accur(a,b))
fprintf('Ошибка I+ =\t%f\n', s_right - accur(a,b))

function resultp = prim(x)
    resultp = -sqrt(1 - x*x);
end
function resultf = func(x) 
    resultf = x / sqrt(1 - x*x);
end
function resulta = accur(a, b)
    resulta = prim(b) - prim(a);
end