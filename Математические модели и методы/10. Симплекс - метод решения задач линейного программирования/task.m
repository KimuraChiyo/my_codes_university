z_coeffs = [7 -5];
equats_coeffs = [6, -3; 0, 1; -9, -3];
equats_ans = [50; 1; -7];
x1 = linspace(0, 5, 1000);
x2_1 = (50 - 6*x1)/-3;
x2_2 = 1 + x1*0;
x2_3 = (-7 + 9*x1)/-3;
[min_dot, min_f_val, exflag, output, l] = linprog(z_coeffs, equats_coeffs, equats_ans, [], [], [0; 0], []);
fprintf('Оптимальная точка: (%f, %f)\nОптимальное значение функции: %f\n', min_dot(1), min_dot(2), min_f_val);


figure;
x = -1:0.01:9;
y = 0:0.01:2;
y1 = (50 - 6*x)/-3;
y2 = 1 + x*0;
y3 = (-7 + 9*x)/-3;
[X, Y] = meshgrid(x, y);
Z = X.*7 - Y.*5; 
z_lim1 = x.*7 - y1.*5;
z_lim2 = x.*7 - y2.*5;
z_lim3 = x.*7 - y3.*5;
plot3(X, Y, Z);
hold on;
plot3(x, y1, z_lim1, 'r-', 'LineWidth', 2);
plot3(x, y2, z_lim2, 'g-', 'LineWidth', 2);
plot3(x, y3, z_lim3, 'b-', 'LineWidth', 2);
grid on
plot3([min_dot(1)], [min_dot(2)], [min_f_val], 'go', 'MarkerSize', 1, 'LineWidth', 5);
text(min_dot(1), min_dot(2), min_f_val, {['x = ', num2str(min_dot(1))], ['y = ', num2str(min_dot(2))], ['z = ', num2str(min_f_val)], [], [], [], []}, 'FontWeight','bold')
title('Графическое решение задачи лин. программирования');
legend('function', '6x1 - 3x2 \leq 50', 'x2 \leq 1', '9x1 + 3x2 \geq 7', 'min');
xlabel('x1'); ylabel('x2'); zlabel('z');