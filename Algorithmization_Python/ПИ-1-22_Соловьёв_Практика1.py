# ПИ-1-22, Соловьёв Л.А.
from math import sqrt, pi

#1.1
print(r"1.1 Вычислить значение функции 7х + 5")
a = int(input('Input x: '))
print("     Ответ: y =", a*7 + 5, end='\n\n')

#1.2
print(r"1.2. Найти периметр квадрата")
a = int(input('Введите сторону квадрата: '))
print("     Ответ: P =", a * 4, end='\n\n')

#1.3
print(r"1.3. Найти длину окружности  ")
a = int(input("Введите радиус: "))
print("     Ответ: l =", 2 * pi * a, end='\n\n')

#1.4
print(r"1.4. Найти периметр прямоугольного треугольника")
a, b = int(input("Введите первый катет: ")), int(input("Введите второй катет: "))
print("     Ответ: P =", a + b + (sqrt(a**2 + b**2)), end='\n\n')

#1.5
print(r'1.5. Найти площадь кольца')
a, b = int(input("Введите радиус внутренней окружности: ")), int(input("Введите радиус внешней окружности: "))
print("     Ответ: S =", pi*(b**2-a**2), end='\n\n')

#1.6
print(r'1.6. Найти периметр равнобедренной трапеции')
a, b, h = int(input("Введите большее основание: ")), int(input("Введите меньшее основание: ")), int(input("Введите высоту: "))
print("     Ответ: P = ", a + b + 2 * sqrt(((a-b)/2)**2 + h**2), end='\n\n')

#1.7
print(r'1.7. Сколько часов и минут будут показывать электронные часы спустя n минут')
n = int(input("Сколько минут прошло с начала суток? "))
print("     Ответ: {} {}\n".format((n // 60) % 24, n % 60))

#2.1
print("2.1  Найти большее из двух вещественных чисел")
a, b = float(input("Введите первое число: ")), float(input("Введите второе число: "))
if b > a:
    print("     Ответ: {} > {}\n".format(b, a))
elif a > b:
    print("     Ответ: {} > {}\n".format(a, b))
else:
    print("     Ответ: {} == {}\n".format(a, b))

#2.2
print("2.2 Найти наименьшее из трёх")
a, b, c = int(input("1 число: ")), int(input("2 число: ")), int(input("3 число: "))
if a < b:
    if a < c:
        print(f"     Ответ: {a}", end='\n\n')
    else:
        print(f"     Ответ: {c}", end='\n\n')
else:
    if b < c:
        print(f"     Ответ: {b}", end='\n\n')
    else:
        print(f"     Ответ: {c}", end='\n\n')

#2.3
print("2.3. Найти среднее из трёх")
a, b, c = int(input("1 число: ")), int(input("2 число: ")), int(input("3 число: "))
if a < b:
    if a > c:
        print(f"     Ответ: {a}", end='\n\n')
    else:
        if b > c:
            print(f"     Ответ: {c}", end='\n\n')
        else:
            print(f"     Ответ: {b}", end='\n\n')
else:
    if b > c:
        print(f"     Ответ: {b}", end='\n\n')
    else:
        if a > c:
            print(f"     Ответ: {c}", end='\n\n')
        else:
            print(f"     Ответ: {a}", end='\n\n')

#2.4
print("2.4. Из двух чисел(чётное и нечётное) вывести нечётное")
a, b = int(input("1 число: ")), int(input("2 число: "))
print("     Ответ: {}".format(b if b%2 else a), end='\n\n')

#2.5
print("2.5. Имеется ли цифра 1 в трёхзначном числе")
a, b, c = input("Введите трёхзначное число: ")
print("     Ответ: Да" if ((a == '1') or (b == '1') or (c == '1')) else "     Ответ: Нет", end='\n\n')

#2.6
print("2.6. Произведение ненулевых цифр числа")
a, b, c = input("Введите трёхзначное число: ")
print(f"     Ответ: {max(1,int(a)) * max(1, int(b)) * max(1, int(c))}", end='\n\n')

#2.7
print("2.7. Вычислить большую площадь(Круг по радиусу или квадрат по стороне)")
print("pi * R**2 = a**2\npi = a**2 / R**2\npi < a**2 / R**2 -> Sкв>Sкр\npi > a**2 / R**2 -> Sкв<Sкр\npi = a**2 / R**2 -> Sкв=Sкр")
a, R = float(input("Введите сторону квадрата: ")), float(input("Введите радиус круга: "))
с = ""
if pi < a**2 / R**2:
    print("     Ответ: Площадь квадрата больше", end='\n\n')
elif pi > a**2 / R**2:
    print("     Ответ: Площадь круга больше", end='\n\n')
else:
    print("     Ответ: Площади равны", end='\n\n')

#2.8
print("2.8. Вычислить значение функции")
x = float(input("Введите х: "))
if x <= -1:
    print(f"     Ответ: y = 1 / x*x = {1 / (x*x)}", end='\n\n')
elif -1 < x < 2:
    print(f"     Ответ: y = x*x = {x*x}", end='\n\n')
else:
    print(f"     Ответ: y = {4}", end='\n\n')

#2.9
print("2.9. Вычислить значение функции u = 3z**2 - 2z + 5")
x, y = float(input("Введите х: ")), float(input("Введите y: "))
z = 0
print(f"     Ответ: z = ", end = '')
if x+y < 2:
    z = sqrt(x**2 + y**2)
    print("sqrt(x**2 + y**2)", end = ' ')
elif ((x+y == 3) or (x+y == 8)):
    z = 2 * x * y
    print("2*x*y", end = ' ')
elif x + y >= 10:
    z = x - y
    print("x-y", end = ' ')
else:
    z = 2*x + 3*y
    print("2*x + 3*y", end = ' ')
print(f"= {z}\tu = {3*z**2 - 2*z + 5}", end='\n\n')

#2.10
print('2.10. Название дня недели по числу')
a = {0: "понедельник", 1: "вторник", 2: "среда", 3: "четверг", 4: "пятница", 5: "суббота", 6: "воскресенье"}
n = int(input("Введете число в диапазоне от 1 до 7(для чисел вне диапазона будет применено кольцо вычета по 7):"))
print(f"     Ответ: {a[(n-1) % 7]}", end = '\n\n')

#2.11
print("2.11. Четверть коорд. плоскости по точке - (х, у)")
x, y = float(input("Введите х: ")), float(input("Введите у: "))
if x*y > 0:
    print("     Ответ: {} четверть".format(3 if x < 0 else 1), end='\n\n')
elif x*y == 0:
    print("     Ответ: {}".format('ось Y' if x == 0 and y != 0 else 'ось X' if y == 0 and x != 0 else 'Center'), end='\n\n')
else:
    print("     Ответ: {} четверть".format(2 if y > 0 else 4), end='\n\n')


# 2.12
print("2.12. Если два числа не равны, то заменить оба на наибольше, иначе заменить нулями")
x, y = int(input("1 число: ")), int(input("2 число: "))
if x == y:
    x, y = 0, 0
else:
    if x > y:
        y = x
    else:
        x = y
print(f"     Ответ: (x, y) = ({x}, {y})", end='\n\n')
