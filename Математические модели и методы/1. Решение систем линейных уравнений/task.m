A = [5, -1, 3; 1, -4, 2; 2, -1, 5];
B = [5; 20; 10];
eps = 1e-6;
x = [0; 0; 0];
k = 0;

for i = 1:3
    s = 0;
    for j = 1:3
        s = s + A(i, j);
        if i == j
            s = s - A(i, j);
        end
    end
    if abs(A(i, i))< abs(s)
        error('')
    end
end

fprintf('1) Решение методом Гаусса:');
A\B
R = rref([A B]);
R

fprintf('2) Решение методом Зейделя:\n');
while k <= 500
    k = k + 1;
    x(1) = (B(1) - A(1, 2)*x(2) - A(1,3)*x(3)) / A(1, 1);
    x(2) = (B(2) - A(2, 1)*x(2) - A(2,3)*x(3)) / A(2, 2);
    x(3) = (B(3) - A(3, 1)*x(2) - A(3,2)*x(3)) / A(3, 3);
end
disp(x);