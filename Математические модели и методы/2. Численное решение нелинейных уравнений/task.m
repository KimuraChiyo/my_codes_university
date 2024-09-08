eps = 1e-6;

% метод простой итерации
count_iter = 1000;
% вычисление корня первого уравнения
x10 = 1;
for i = 1:count_iter
    x11 = (exp(-2 * x10) + 1) / 2;
    if abs(x11 - x10) < eps
        break;
    end
    x10 = x11;
end
% вычисление корня второго уравнения
x20 = 1; 
for i = 1:count_iter
    x21 = (5^x20 - 3) / 6;
    if abs(x21 - x20) < eps
        break;
    end
    x20 = x21;
end


% метод половинного деления
% функция первого уравнения
func1 = @(x) exp(-2*x) - 2 * x + 1;
% функция второго уравнения
func2 = @(x) 5^x - 6*x - 3;
% интервал изоляции корня первого уравнения
a1 = -1; 
b1 = 1; 
% интервал изоляции корня второго уравнения
a2 = -1; 
b2 = 1; 
% вычисление корня первого уравнения
while (b1 - a1) / 2 > eps
    c1 = (a1 + b1) / 2;
    if func1(c1) == 0
        break;
    elseif func1(a1) * func1(c1) < 0
        b1 = c1;
    else
        a1 = c1;
    end
end
% вычисление корня первого уравнения
while (b2 - a2) / 2 > eps
    c2 = (a2 + b2) / 2;
    if func2(c2) == 0
        break;
    elseif func2(a2) * func2(c2) < 0
        b2 = c2;
    else
        a2 = c2;
    end
end

% метод касательных
% производные первой функции
func1_proizv = @(x) -2*exp(-2 * x) - 2;
func1_double_proizv = @(x) 4*exp(-2 * x);
% производные второй функции
func2_proizv = @(x) 5^x * log(5) - 6;
func2_double_proizv = @(x) 5^x * log(5)^2;
% интервал изоляции корня
a31 = -1; 
b31 = 1; 
% выбор начального приближения корня первого уравнения
if func1(a31)*func1_double_proizv(a31) > 0
    x31 = a31;
else
    x31 = b31;
end
% выбор начального приближения корня второго уравнения
if func2(a31)*func2_double_proizv(a31) > 0
    x32 = a31;
else
    x32 = b31;
end
% вычисление корня первого уравнения
for i = 1:count_iter
    x31 = x31 - func1(x31) / func1_proizv(x31);
    if abs(func1(x31)) < eps
        break;
    end
end
% вычисление корня второго уравнения
for i = 1:count_iter
    x32 = x32 - func2(x32) / func2_proizv(x32);
    if abs(func2(x32)) < eps
        break;
    end
end

% метод хорд
x40 = 0;
x41 = x40 - func1(x40);
for i = 1:count_iter
    ans1 = x41 - func1(x41) * (x41 - x40) / (func1(x41) - func1(x40));
    if abs(func1(ans1)) < eps
        break;
    end
    x40 = x41;
    x41 = ans1;
end
x40 = 0; 
x41 = x40 - func2(x40);
for i = 1:count_iter
    ans2 = x41 - func2(x41) * (x41 - x40) / (func2(x41) - func2(x40));
    if abs(func2(ans2)) < eps
        break;
    end
    x40 = x41;
    x41 = ans2;
end


fprintf('\nМетод простой итерации\n')
fprintf('Корень первого уравнения: %f\n', x10);
fprintf('Корень второго уравнения: %f\n', x20);
fprintf('\nМетод половинного деления\n')
fprintf('Корень первого уравнения: %f\n', (a1 + b1) / 2);
fprintf('Корень второго уравнения: %f\n', (a2 + b2) / 2);
fprintf('\nМетод касательных\n')
fprintf('Корень первого уравнения: %f\n', x31);
fprintf('Корень второго уравнения: %f\n', x32);
fprintf('\nМетод хорд\n')
fprintf('Корень первого уравнения: %f\n', ans1);
fprintf('Корень второго уравнения: %f\n', ans2);


% функция первого уравнения
func1 = @(x) exp(-2*x) - 2 * x + 1;
x = -1:0.001:1;
y = func1(x);
figure;
hold on;
plot(x, y, 'LineWidth', 1);
xline(0, 'LineWidth', 1)
yline(0, 'LineWidth', 1)
title('График функции f(x) = e в степени (-2*x) - 2x + 1');
xlabel('x');
ylabel('f(x)');
hold off;
grid on;


% функция второго уравнения
func2 = @(x) 5.^x - 6*x - 3;
x = -1:0.01:2;
y = func2(x);
figure;
hold on;
plot(x, y, 'LineWidth', 1);
xline(0, 'LineWidth', 1)
yline(0, 'LineWidth', 1)
title('График функции f(x) = 5^x - 6x - 3');
xlabel('x');
ylabel('f(x)');
grid on;
hold off;
