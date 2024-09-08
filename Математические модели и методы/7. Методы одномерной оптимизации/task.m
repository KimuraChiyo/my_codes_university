% f(x) = 31.75*x^2 - 15.25*x + 2 на интервале [0, 1]
eps = 0.001;
a = 0;
b = 1;
h = 0.1;

x_scan = scanning(a, h, eps);
fprintf("Метод сканирования\nx = %f\ny(x) = %f\n\n", x_scan, func(x_scan));

x_dicho = dichotomy(a, b, eps);
fprintf("Метод дихотомии\nx = %f\ny(x) = %f\n\n", x_dicho, func(x_dicho));

x_gold = golden_ratio(a, b, eps);
fprintf("Метод золотого сечения\nx = %f\ny(x) = %f\n\n", x_gold, func(x_gold));

x_fib = fib_method(a, b, eps);
fprintf("Метод Фибоначчи\nx = %f\ny(x) = %f\n\n", x_fib, func(x_fib));

x_accur = fminbnd(@func, a, b);
fprintf("Точное значение\nx = %f\ny(x) = %f\n\n", x_accur, func(x_accur));

plot(x_accur, func(x_accur), 'g.');
text(x_accur, func(x_accur), {['x = ', num2str(x_accur)], ['y = ', num2str(func(x_accur))]})
hold on
fplot(@func, [a b], 'r-');
title('График функции y = (127/4) * x.^2 - (61/4)*x + 2;')
xlabel('x');
ylabel('y');


function min_x = scanning(f_a, f_h, f_eps)
    while f_h > f_eps
        min_x = f_a;
        while 1
            if func(min_x) > func(min_x + f_h)
                min_x = min_x + f_h;
            else
                f_a = min_x - 2*f_h;
                f_h = f_h / 3;
                break;
            end
        end
    end
end

function x_opt = dichotomy(f_a, f_b, f_eps)
    while abs(f_a - f_b) > 2 * f_eps
        x1 = (f_a + f_b - f_eps) / 2;
        x2 = (f_a + f_b + f_eps) / 2;
        if func(x1) < func(x2)
            f_b = x2;
        else
            f_a = x1;
        end
    end
    x_opt = (f_a + f_b) / 2;
end

function x_opt = golden_ratio(f_a, f_b, f_eps)
    x1 = f_a + 0.382*(f_b - f_a);
    x2 = f_a + 0.618*(f_b - f_a);
    while abs(f_b - f_a) > f_eps
        if func(x1) >= func(x2)
            f_a = x1;
            x1 = x2;
            x2 = f_a + 0.618*(f_b - f_a);
        else
            f_b = x2;
            x2 = x1;
            x1 = f_a + 0.382*(f_b - f_a);
        end
    end
    x_opt = (f_a + f_b) / 2;
end

function x_opt = fib_method(f_a, f_b, f_eps)
    n = 0;
    while fibonacci(n) <= ((f_b - f_a) / f_eps)
        n = n + 1;
    end
    k = 0;
    x1 = f_a + fibonacci(n - 2) * (f_b - f_a) / fibonacci(n);
    x2 = f_a + fibonacci(n - 1) * (f_b - f_a) / fibonacci(n);
    while abs(x2 - x1) > f_eps
        if func(x1) <= func(x2)
            f_b = x2;
            x2 = x1;
            x1 = f_a + fibonacci(n - k - 3) * (f_b - f_a) / fibonacci(n - k - 1);
            if k ~= n - 3
                k = k + 1;
            else
                x1 = (f_a + f_b) / 2;
                x2 = x1 + f_eps;
            end
        else
            f_a = x1;
            x1 = x2;
            x2 = f_a + fibonacci(n - k - 2) * (f_b - f_a) / fibonacci(n - k - 1);
        end
    end
    x_opt = (f_a + f_b) / 2;
end

function fib = fibonacci(n)
    if n == 1
        fib = 1;
    elseif n == 2
        fib = 1;
    elseif n > 2
        fib = fibonacci(n - 1) + fibonacci(n - 2);
    else
        fib = 0;
    end
end

function y = func(x)
    y = (127/4) * x.^2 - (61/4)*x + 2;
    %y = 0.1*x.^3 - 2*x.^2 + 10*x;
end