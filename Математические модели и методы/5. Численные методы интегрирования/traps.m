a = 0;
b = 0.9;
n = 18;
h = (b-a)/n;
s = 0;
for i = 0:n-1
    xi = h*i;
    xi1 = h*(i+1);
    s = s + h * (func(xi) + func(xi1)) / 2;
end
fprintf('Метод трапеций\nx/sqrt(1-x^2)\n\n');
fprintf('I = %f\n\n', s);
fprintf('Точное значение =\t%f\n\n', accur(a, b));
fprintf('Ошибка I = %f\n', s - accur(a,b))

% Возможно дополнить с помощью syms x из Symbolic Math Toolbox
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