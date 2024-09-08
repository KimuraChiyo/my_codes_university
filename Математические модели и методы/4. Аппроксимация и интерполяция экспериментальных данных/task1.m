x = [70.7; 71.6; 72.4; 77.2; 73.7; 76.5; 79.3; 79.6; 70; 76.7; 73.6; 78.1; 74.6; 87.3;];
y = [27.2; 27.5; 28.8; 27.1; 27; 28; 28.1; 28; 27.9; 28; 28.2; 28; 27.9; 28.5;];
p1 = polyfit(x, y, 1);
p2 = polyfit(x, y, 2);
p3 = polyfit(x, y, 3);

t = 69:0.01:90;
y1 = polyval(p1, t);
y2 = polyval(p2, t);
y3 = polyval(p3, t);

plot(x, y, 'ko', t, y1, 'r-', t, y2, 'g--', t, y3, 'm:'); 
grid on;
xlabel('x'); ylabel('y');
title('График регрессии');
legend('Табличные данные', 'Прямая', 'Парабола', 'Кубическая парабола');

a = p1(1);
b = p1(2);

fprintf("Ур-е лин. регрессии: y = %f * x + %f\n", a, b);
prev_y = a * x + b;
top = sum((prev_y - mean(y)).^2);
down = sum((y - mean(y)).^2);
r_square = top / down;
fprintf("Коэф. детерминации R^2 = %f\n", r_square);
fprintf("Влияние факторов вне регрес. модели - %f%%\n", (1 - r_square) * 100);
fprintf("Вывод: Делать прогноз y*=f(x*) невозможно\n");

