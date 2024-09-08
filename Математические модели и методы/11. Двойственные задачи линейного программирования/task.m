z_coeffs = [7 -5];
equats_coeffs = [6, -3; 0, 1; -9, -3];
equats_ans = [50; 1; -7];
x1 = linspace(0, 5, 1000);
x2_1 = (50 - 6*x1)/-3;
x2_2 = 1 + x1*0;
x2_3 = (-7 + 9*x1)/-3;
[min_dot, min_f_val] = linprog(z_coeffs, equats_coeffs, equats_ans, [], [], [0; 0], []);
[max_dot, max_f_val] = linprog(-z_coeffs, equats_coeffs, equats_ans, [], [], [0; 0], []);
[max_dv_dot, max_dv_f_val] = linprog(equats_ans, -equats_coeffs', z_coeffs, [], [], [0; 0; 0], []);
[min_dv_dot, min_dv_f_val] = linprog(equats_ans, -equats_coeffs', -z_coeffs, [], [], [0; 0; 0], []);
fprintf('Точка минимума прямой задачи: (%f, %f)\nМинимальное значение функции прямой задачи: %f\n', min_dot(1), min_dot(2), min_f_val);
fprintf('Точка максимума дв. задачи:\n\t\t\t\t\t(%f, %f, %f)\nМаксимальное значение функции дв. задачи: %f\n', max_dv_dot(1), -max_dv_dot(2), -max_dv_dot(3), -max_dv_f_val);

fprintf('\nТочка максимума прямой задачи: (%f, %f)\nМаксимальное значение функции прямой задачи: %f\n', max_dot(1), max_dot(2), -max_f_val);
fprintf('Точка минимума дв. задачи:\n\t\t\t\t\t(%f, %f, %f)\nМинимальное значение функции дв. задачи: %f\n', min_dv_dot(1), min_dv_dot(2), min_dv_dot(3), min_dv_f_val);

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
plot3([min_dot(1) max_dot(1)], [min_dot(2) max_dot(2)], [min_f_val -max_f_val], 'go', 'MarkerSize', 1, 'LineWidth', 5);
text(6, -15, 150, {['Двойственная задача:'], ['z = 50y_1  + y_2 - 7y_3'], ['6y1 - 9y3 \geq 7'], ['-3y_1 + y_2 - 3*y_3 \geq -5'], ['y_1 \geq 0, y_2 \geq 0, y_3 \geq 0']})
title('Графическое решение задачи лин. программирования');
legend('function', '6x_1 - 3x_2 \leq 50', 'x_2 \leq 1', '9x_1 + 3x_2 \geq 7', 'min');
xlabel('x1'); ylabel('x2'); zlabel('z');


