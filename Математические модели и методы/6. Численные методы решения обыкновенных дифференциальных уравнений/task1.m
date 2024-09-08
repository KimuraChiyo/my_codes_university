a = 0;
n = 8;
h = 0.25;
yi_start = 2;
yi_classic = yi_start;
yi_runge_kutt = yi_start;
yi_classic_list = [];
yi_runge_kutt_list = [];

yi_accur_1 = ode45(@diffy, [a a+8*h], yi_start);
yi_accur = [yi_accur_1.y(1:1:9)];

fprintf('Решения ((((8 + 12*cos(x)) * exp(2*x)) / y) - 3*y*cos(x)) / 2\n');
fprintf('\tx\t\t|  Метод Эйлера\t|  Рунге-Кутт\t|\tТочн. знач.\t|\n');
for i = 0:n
    yi_classic_list = [yi_classic_list, yi_classic];
    yi_runge_kutt_list = [yi_runge_kutt_list, yi_runge_kutt];
    xi = a + h*i;
    fprintf('\t%.2f\t|\t%f\t|\t%f\t|\t%f\t|\n', xi, yi_classic, yi_runge_kutt, yi_accur(i+1));
    yi_classic = yi_classic + h * diffy(xi, yi_classic);
    k0 = h * diffy(xi, yi_runge_kutt);
    k1 = h * diffy(xi + h/2, yi_runge_kutt + k0 / 2);
    k2 = h * diffy(xi + h/2, yi_runge_kutt + k1 / 2);
    k3 = h * diffy(xi + h, yi_runge_kutt + k2);
    yi_runge_kutt = yi_runge_kutt + (k0 + 2*k1 + 2*k2 + k3)/6;
end

x_graph = a:h:a+h*n;
plot(x_graph, yi_accur, 'ko', x_graph, yi_classic_list, 'g-', x_graph, yi_runge_kutt_list, 'r-');
title('((((8 + 12*cos(x)) * exp(2*x)) / y) - 3*y*cos(x)) / 2');
xlabel('x'); ylabel('y');
legend('Точные данные', 'Метод Эйлера', 'Метод Рунге-Кутта');

function res = diffy(x, y)
    res = ((((8 + 12*cos(x)) * exp(2*x)) / y) - 3*y*cos(x)) / 2;
end
