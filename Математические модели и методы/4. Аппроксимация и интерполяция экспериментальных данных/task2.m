T = [100, 120, 140, 160, 180];
P = [101.33, 198.5, 361.36, 618.04, 1002.7];

need_T = 170;

P_newton = newton(T, coefficients(T, P), need_T); format long g
fprintf("Интерполяция полиномами Ньютона\n");
fprintf("Значение P(%.0f) = %f\n\n", need_T, P_newton)
fprintf("Интерполяционный метод Лагранжа\n");
P_lagrange = lagrange(T, P, need_T);
fprintf("Значение P(%.0f) = %f\n\n", need_T, P_lagrange);

function result_coeffs = coefficients(func_T, func_P) 
    n = length(func_T);
    result_coeffs = zeros(n, n);
    result_coeffs(:, 1) = func_P;
    for j = 2:n
        for i = 1:n-j+1
            result_coeffs(i, j) = (result_coeffs(i+1, j-1) - result_coeffs(i, j-1));
        end
    end
end

function res = newton(f_T, f_coefficients, f_need_T)
    n = length(f_T);
    i = n;
    j = 1;
    res = f_coefficients(i, j);
    const_q = (f_need_T - f_T(n)) / 20;
    q_top = const_q;
    q_down = 1;
    curr = 1;
    while i ~= 1
        i = i - 1; j = j + 1;
        res = res + f_coefficients(i, j) * (q_top / q_down);
        q_top = q_top * (const_q + 1);
        curr = curr + 1;
        q_down = factorial(curr);
    end
end

function res = lagrange(f_T, f_P, f_need_T)
    n = length(f_T);
    res = 0;

    for i=1:n
        part = f_P(i);
        for j=1:n
            if i ~= j
                part = part * ((f_need_T - f_T(j)) / (f_T(i) - f_T(j)));
            end
        end
        res = res + part;
    end
end
