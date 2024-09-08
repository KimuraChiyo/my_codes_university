a = 0;
n = 15;
h = 0.1;
yi_start = 1;
yi_classic = yi_start;
yi_mod = yi_start;
yi_runge_kutt = yi_start;
yi_classic_list = [];
yi_mod_list = [];
yi_runge_kutt_list = [];

yi_accur_1 = ode45(@diffy, [a a+10*h], yi_start);
yi_accur_2 = ode45(@diffy, [a+10*h a+20*h], yi_accur_1.y(11));
yi_accur = [yi_accur_1.y, yi_accur_2.y(2:1:6)];

fprintf('Решения cos(x + y) + 0.75 * (x - y)\n');
fprintf('\t x\t|  Метод Эйлера\t|  Модиф. Эйлер\t|  Рунге-Кутт\t|  Точн. знач.\t|\n');
for i = 0:n
    yi_classic_list = [yi_classic_list, yi_classic];
    yi_mod_list = [yi_mod_list, yi_mod];
    yi_runge_kutt_list = [yi_runge_kutt_list, yi_runge_kutt];
    xi = a + h*i;
    fprintf('\t%.1f\t|\t%f\t|\t%f\t|\t%f\t|\t%f\t|\n', xi, yi_classic, yi_mod, yi_runge_kutt, yi_accur(i+1));
    yi_classic = yi_classic + h * diffy(xi, yi_classic);
    yi_mod = yi_mod + h * diffy(xi + h/2, yi_mod + h * diffy(xi, yi_mod)/2);
    k0 = h * diffy(xi, yi_runge_kutt);
    k1 = h * diffy(xi + h/2, yi_runge_kutt + k0 / 2);
    k2 = h * diffy(xi + h/2, yi_runge_kutt + k1 / 2);
    k3 = h * diffy(xi + h, yi_runge_kutt + k2);
    yi_runge_kutt = yi_runge_kutt + (k0 + 2*k1 + 2*k2 + k3)/6;
end

x_graph = a:h:a+h*n;
plot(x_graph, yi_accur, 'ko', x_graph, yi_classic_list, 'g-', x_graph, yi_mod_list, 'b-', x_graph, yi_runge_kutt_list, 'r--');
title('Решения cos(x + y) + 0.75 * (x - y)');
xlabel('x'); ylabel('y');
legend('Табличные данные', 'Метод Эйлера', 'Модифицированный метод Эйлера', 'Метод Рунге-Кутта');

function res = diffy(x, y)
    res = cos(x + y) + 0.75 * (x - y);
    % res = 2*(x.^2 + y);
end