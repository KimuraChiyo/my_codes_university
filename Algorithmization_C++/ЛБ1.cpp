#include <iostream>  
#include <cmath>
#include <locale.h>
//1.1 задача
/*int main() {
	int m, n; float x, t; double z;
	std::cout << "Enter m:\n"; std::cin >> m;
	std::cout << "Enter n(n > m):\n"; std::cin >> n;
	std::cout << "Enter x:\n"; std::cin >> x;
	std::cout << "Enter t:\n"; std::cin >> t;
	std::cout << "m:" << m << '\n' << "n:" << n << '\n' << "x:" << x << '\n' << "t:" << t << '\n';
	float phi = exp(sin(t)) - exp(cos(t));
	std::cout << "phi:" << phi << '\n';
	if (phi == x) {
		z = phi * phi * pow(pow(x, n), 1. / 4) / (pow(phi, (double)n / m) * x);
	}
	else {
		if (x < phi) {
			z = sin(pow(double(m) / n, (x * x) / (x + phi)));
		}
		else {
			z = pow(log(phi) / log((double)m / n), (double)n / m);
		}
	}
		std::cout << "z = " << z;
	return 11;
}*/
//1.2 задача
/*int main() {
	int k, n; float t, y;
	double const pi = acos(-1.);
	std::cout << "Enter k:\n"; std::cin >> k;
	std::cout << "Enter n:\n"; std::cin >> n;
	std::cout << "Enter t:\n"; std::cin >> t;
	std::cout << "k:" << k << '\n' << "n:" << n << '\n' << "t:" << t << '\n';
	if (t <= 0) {
		y = exp(((float)k / n * t) - 1);
	}
	else {
		if ((t <= pi / 2) || (k * pi / n <= t <= pi)) {
			y = cos(abs((float)n / k * t));
		}
		else {
			y = log(pow(pow(log(t), n), 1. / k));
		}
	}
	std::cout << "y = " << y;
	return 12;
}*/
//2.7 задача
/*int main() {
	float a, b;
	std::cout << "Enter a:\n"; std::cin >> a;
	std::cout << "Enter b:\n"; std::cin >> b;
	std::cout << "Halfsum: " << (a + b) / 2. << "\nDoublemul: " << 2 * a * b << '\n';
	if (a > b) {
		float c = a;
		a = (b + a) / 2.;
		b *= 2 * c;
	}
	else {
		float c = b;
		b = (b + a) / 2.;
		a *= 2 * c;
	}
	std::cout << "a = " << a << "\nb = " << b;
	return 21;
}*/
//2.8 задача
/*int main() {
	float a, b, c;
	std::cout << "Enter a:\n"; std::cin >> a;
	std::cout << "Enter b:\n"; std::cin >> b;
	std::cout << "Enter c:\n"; std::cin >> c;
	std::cout << "---------------\n";
	std::cout << "First condition\n";
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "c: " << c << '\n';
	a < b ? a < c ? a = 0 : c = 0 : b < c ? b = 0 : c = 0;
	std::cout << "---------------\n";
	std::cout << "Second condition\n";
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "c: " << c << '\n';
	std::cout << "---------------";
	return 28;
}*/
//3.3 задача
//комментарий
/*
0 лет
1 год 
2-4 года
5-20 лет
21 год
22-24 года
25 лет
Eсли остаток от деления на 20 == 0 или лежит в [5, 19], то лет
Eсли % 20 == 1, то год
Eсли остаток от деления на 20 лежит в [2, 4], то года
Русский язык не выводился, нашёл фикс пробелемы в интернете 
Подключена доп.библиотека locale.h
*/
//код
/*int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	std::cout << "Введите возраст [0,25]: "; std::cin >> N;
	while (N < 0 || N > 25) {
		std::cout << "Введите возраст [0,25]: ";
		std::cin >> N;
	}
	if (N % 20 == 1)
		std::cout << "Мне " << N << " год";
	else if (1 < N % 20 < 5) 
		std::cout << "Мне " << N << " года";
	else 
		std::cout << "Мне " << N << " лет";
	return 2;
}*/
//3.7 задача
/*int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Добро пожаловать в преобразователь числа в диапазоне от -9 до 9";
	int N; char m;
	goto m2;
	m0:
	std::cout << "Введите число от -9 до 9: "; std::cin >> N;
	while (N > 9 || N < -9) {
		std::cout << "Введите число от -9 до 9: "; std::cin >> N;
	}
	if (N < 0)
		std::cout << "минус ";
	else
		goto m1;
	m1:
	switch (abs(N))
	{
	case 0: { std::cout << "ноль"; break; }
	case 1: { std::cout << "один"; break; }
	case 2: { std::cout << "два"; break; }
	case 3: { std::cout << "три"; break; }
	case 4: { std::cout << "четыре"; break; }
	case 5: { std::cout << "пять"; break; }
	case 6: { std::cout << "шесть"; break; }
	case 7: { std::cout << "семь"; break; }
	case 8: { std::cout << "восемь"; break; }
	case 9: { std::cout << "девять"; break; }
	}
	m2:
	{
		std::cout << "\nХотите ли вы преобразовать число? д(y)/н(n)\n"; std::cin >> m;
		if (m == 'д' || m == 'y')
			goto m0;
		else
			goto m4;
	}
	m4:
	std::cout << "Спасибо, что воспользовались преобразователем числа в диапазоне от -9 до 9";
	return 3.7;
}*/
//ДЗ1а
int main() {
	setlocale(LC_ALL, "Russian");
	float x, y, z, sum, mul;
	std::cout << "Введите x: "; std::cin >> x;
	std::cout << "Введите y: "; std::cin >> y;
	std::cout << "Введите z: "; std::cin >> z;
	sum = x + y + z;
	mul = x * y * z;
	sum < mul ? std::cout << mul; : std::cout sum;
	return 11;
}