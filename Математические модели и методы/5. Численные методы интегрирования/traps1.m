a = 0;
b = pi;
n = 1000;
h = (b-a)/n;
s = 0;
for i = 0:n-1
    xi = h*i;
    xi1 = h*(i+1);
    s = s + h * (func(xi) + func(xi1)) / 2;
end
fprintf('Метод трапеций\nexp(x).*sin(x)\n\n');
fprintf('I = %f\n\n', s);
x = a:1/10000:b;
y = func(x);
accur = trapz(x, y);
fprintf('Точное значение =\t%f\n\n', accur);
fprintf('Ошибка I = %f\n', s - accur)

function resultf = func(x) 
    resultf = exp(x).*sin(x);
end