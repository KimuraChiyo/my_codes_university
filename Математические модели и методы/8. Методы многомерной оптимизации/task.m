x10 = -1;
x20 = -1;
eps = 0.001;

start_dot = [x10, x20]

opt_dot = gauss_zeidel_method(start_dot, eps);
x1_opt = opt_dot(1);
x2_opt = opt_dot(2);
fprintf("Метод Гаусса-Зейделя\nx1 = %.10f\tx2 = %.10f\ny(x1, x2) = %f\n\n", x1_opt, x2_opt, func(x1_opt, x2_opt));

opt_dot = gradient_method(start_dot, eps);
x1_opt = opt_dot(1);
x2_opt = opt_dot(2);
fprintf("Метод градиента\nx1 = %.10f\tx2 = %.10f\ny(x1, x2) = %f\n\n", x1_opt, x2_opt, func(x1_opt, x2_opt));

opt_dot = fastest_descent_method(start_dot, eps);
x1_opt = opt_dot(1);
x2_opt = opt_dot(2);
fprintf("Метод наискорейшего спуска\nx1 = %.10f\tx2 = %.10f\ny(x1, x2) = %f\n\n", x1_opt, x2_opt, func(x1_opt, x2_opt));

[x, f] = fminsearch(@func_dot, start_dot);
x1_acc = x(1);
x2_acc = x(2);
fprintf("Точное значение\nx1 = %.10f\tx2 = %.10f\ny(x1, x2) = %.13f\n\n", x1_acc, x2_acc, f);


function opt_dot = gauss_zeidel_method(f_dot, f_eps)
    while true
        x_last = f_dot(1);
        y_last = f_dot(2);
        x_new = fminunc(@(x_last) func(x_last, f_dot(2)), f_dot(1));
        y_new = fminunc(@(y_last) func(f_dot(1), y_last), f_dot(2));
        
        if norm([x_new - x_last, y_new - y_last]) < f_eps
            break;
        end
        
        f_dot(1) = x_new;
        f_dot(2) = y_new;
    end
    opt_dot = f_dot;
end

function opt_dot = gradient_method(f_dot, f_eps)
    f_new_dot = f_dot;
    alpha = 0.001;
    while true

        if norm(gradient(f_dot)) < f_eps
            break;
        end

        f_new_dot = f_dot - 0.0001 * gradient(f_dot);
        
        if abs(func_dot(f_new_dot) - func_dot(f_dot)) < 0
            if abs(func_dot(f_new_dot) - func_dot(f_dot)) < f_eps & (f_new_dot - f_dot) < f_eps
                break;
            end
        else
            alpha = alpha * 3 / 4;
        end

        f_dot = f_new_dot;
    end
    opt_dot = f_new_dot;
end

function opt_dot = fastest_descent_method(f_dot, f_eps)
    f_new_dot = f_dot;
    while true

        if norm(gradient(f_dot)) < f_eps 
            break;
        end

        alpha = fminsearch(@(alpha) func_dot(f_dot - alpha * gradient(f_dot)), 0);
        f_new_dot = f_dot - alpha * gradient(f_dot);
        % без этого условия работает точнее
        %if abs(func_dot(f_new_dot) - func_dot(f_dot)) < f_eps & (f_new_dot - f_dot) < f_eps
        %    break;
        %end
        f_dot = f_new_dot;
    end
    opt_dot = f_new_dot;
end

function y = func(x1, x2)
    y = 10*(x1.^2 - x2).^2 + (x1 - 1).^2;
end

function grad = gradient(arr)
    x = arr(1);
    y = arr(2);
    grad = [1, 1];
    grad(1) = 40*x.^3 + (2 - 40*y)*x - 2;
    grad(2) = 20*y - 20*x.^2;
end

function y = func_dot(arr)
    x1 = arr(1);
    x2 = arr(2);
    y = 10*(x1.^2 - x2).^2 + (x1 - 1).^2;
end