a = 2;
b = 3;
n = 1000;
h = (b-a)/n;
s = 0;
for i = 0:n-1
    xi = h*i;
    xi1 = h*(i+1);
    s = s + h * (func(xi) + func(xi1)) / 2;
end
fprintf('Метод трапеций\nsqrt(1 - 0.1*(sin(x)).^2)\n\n');
fprintf('I = %f\n\n', s);
x = a:1/10000:b;
y = func(x);
accur = trapz(x, y);
fprintf('Точное значение =\t%f\n\n', accur);
fprintf('Ошибка I = %f\n', s - accur)

function resultf = func(x) 
    resultf = sqrt(1 - 0.1*(sin(x)).^2);
end