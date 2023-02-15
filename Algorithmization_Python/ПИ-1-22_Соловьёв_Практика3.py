from math import factorial, log2, ceil
from random import randint

#1
print("1. Трехзнач. число. Найти сумму и произведение чисел")
a, b, c = input("Введите трёхзначное число: ")
print(f"     Ответ: Сумма: {int(a)+int(b)+int(c)}\n            Произведение: {int(a)*int(b)*int(c)}", end='\n'*2)

#2
print("2. Вывести первую цифру с конца числа")
print(f"     Ответ: {int(input('Введите число: '))%10}", end='\n'*2)

#3
print("3. Число - abc, получить - bca")
print(f"     Ответ: {(a:=int(input('Введите число: ')))%100*10 + a//100}", end='\n'*2)

#4
print('4. Дано число n секунд. Найти число секунд, прошедших с последней минуты')
print(f"     Ответ: {int(input('Введите число секунд: '))%60}", end='\n'*2)

#5
print('5. Дано число n секунд. Найти число полных минут, прошедших с последнего часа')
print(f"     Ответ: {int(input('Введите число секунд: '))%3600//60}", end='\n'*2)

#6
print("6. Компьютер загадывает число[1,n]. У user'а k попыток. ")
num = randint(1, (n:=int(input("Введите число n: "))))
k = int(input(f"Введите число попыток(Рекомендуемое число по bin.search: {ceil(log2(n))}): "))
for i in range(1, k+1):
    l = int(input(str(i) + " попытка. Введите число: "))
    if l < num:
        print("Ваше число меньше.")
    elif l > num:
        print("Ваше число больше.")
    else:
        print("Вы угадали.\n")
        break
else:
    print("Попытки закончились.\n")

#7
print('7. Найти цифровой корень числа')
a = input('Введите число: ')
while len(a) > 1:
    summ = 0
    for i in a:
        summ += int(i)
    a = str(summ)
print(f"     Ответ: {a}", end='\n'*2)

#8
print('8. Все счастливые комбинации в счастливом билете')
print(f"     Ответ: ", end = '')
for i in range(100000, 999999+1):
    n = str(i)

    first = 0
    for k in n[:3]:
        first += int(k)

    second = 0
    for k in n[3:]:
        second += int(k)

    if first == second and i != 999999:
        print(i, end = ', ')
    elif first == second and i == 999999:
        print(i, end = '\n'*2)

#9
print('9. Все числа, сумма факториалов цифр которых равна самому числу')
print(f"     Ответ: ", end ='')
for i in range(1, 40586):
    n = str(i)

    sum_fact = 0
    for k in n:
        sum_fact += factorial(int(k))

    if sum_fact == i and i != 40585:
        print(i, end = ', ')
    elif sum_fact == i and i == 40585:
        print(i, end='\n'*2)

#10
print("10. Перевести число в p-ричную систему счисления(p = 2, 3, ..., 9)")
n = int(input("Введите число: "))
print(f"     Ответ: ", end ='')
for i in range(2, 10):
    c = ''
    b = n
    while b > 0:
        c += str(b % i)
        b //= i
    print(f"{i}-ичная СС: {int(c[::-1])}", end = (", " if i != 9 else '\n\n'))

#11
print('11. Проверить истинность высказывания "Число n является положительным"')
print(f"     Ответ: {int(input('Введите число: ')) > 0}", end = '\n'*2)

#12
print('12. Каждое из чисел a и b нечётное')
print(f"    Ответ: {bool(abs(int(input('Введите  a: ')))%2 and abs(int(input('Введите  b: ')))%2)}", end = '\n'*2)

#13
print('13. Хотя бы одно из чисел a, b и с положительное')
print(f"    Ответ: {bool(int(input('Введите  a: '))>0 or int(input('Введите  b: '))>0 or int(input('Введите  c: '))>0)}", end = '\n'*2)

#14
print('14. Ровно одно из чисел a, b и с положительное')
print(f"    Ответ: {bool(int(input('Введите  a: '))>0) + bool(int(input('Введите  b: '))>0) + bool(int(input('Введите  c: '))>0) == 1}", end = '\n'*2)

#15
print('15. Проверить различность всех цифр в трёхзначном числе')
a, b, c = input("Введите число: ")
print(f"     Ответ: {a != b and a != c and b != c}", end = '\n'*2)

#16
print('16. Проверить, что две клетки шахм.поля обладают одинаковым цветом')
x1, y1, x2, y2 = int(input("Введите х1[1,8]: ")), int(input("Введите y1[1,8]: ")), int(input("Введите х2[1,8]: ")), int(input("Введите y2[1,8]: "))
print(f"     Ответ: {(x1+y1)%2 == (x2+y2)%2}", end = '\n'*2)

#17
print("17. Проверить, что конь может сходить с 1-го поля на 2-ое поле")
x1, y1, x2, y2 = int(input("Введите х1[1,8]: ")), int(input("Введите y1[1,8]: ")), int(input("Введите х2[1,8]: ")), int(input("Введите y2[1,8]: "))
dx, dy = abs(x1 - x2), abs(y1 - y2)
print(f"     Ответ: {(dx == 2 and dy == 1) or (dx == 1 and dy == 2)}", end = '\n'*2)

#18
print('18. Вывести описание числа вида "чёт-/нечёт-ное одно-/дву-/трёх-значное число"')
n = int(input("Введите число: "))
a = [ 'чётное', 'нечётное']
b = [ 'заглушка для удобства', 'однозначное', 'двузначное', 'трёхзначное']
print(f"     Ответ: {a[n%2] + ' ' + b[len(str(n))] + ' число'}", end = '\n'*2)

#19
print("19. Вывести словесное представление чисел 20-69")
l = [' ', ' один ', ' два ', ' три ', ' четыре ', ' пять ', ' шесть ', ' семь ', ' восемь ', ' девять ']
print("     Ответ: ",)
for n in range(20, 70):
    s = ''
    if n // 10 == 2:
        s = 'двадцать'
    elif n // 10 == 3:
        s = 'тридцать'
    elif n // 10 == 4:
        s = 'сорок'
    elif n // 10 == 5:
        s = 'пятьдесят'
    elif n // 10 == 6:
        s = 'шестьдесят'


    s += l[n%10]

    if n % 10 == 1:
        s += "год"
    elif n % 10 in [2, 3, 4]:
        s += "года"
    else:
        s += "лет"

    print('            ',n, '-', s)

#20
print('\n20. 1 - сложениe, 2 — вычитание, 3 — умножение, 4 — деление. Простейший калькулятор. Числа вводятся пользователем')
sep = int(input("Введите арифм. знак: "))
a, b = float(input("Введите первое число: ")), float(input("Введите второе число: "))
if sep == 1:
    print(f"     Ответ: {a+b}", end='\n'*2)
elif sep == 2:
    print(f"     Ответ: {a-b}", end='\n'*2)
elif sep == 3:
    print(f"     Ответ: {a*b}", end='\n'*2)
elif sep == 4:
    print(f"     Ответ: {a/b}", end='\n'*2)

#21
print("21. Буква направления «С» - север, «З» - запад, «Ю» - юг, «В» - восток. Число 0 - продолжать движение, 1 - поворот налево, –1 - поворот направо")
a = ['С', 'З', 'Ю', 'В']
b = input("Введите исходное направление робота(С, З, Ю, В): ")
c = int(input("Введите число поворота(-1 ,0, 1): "))
print(f"     Ответ: {a[(a.index(b)+c) % 4]}", end='\n'*2)

#22
print("22. Буква направления «С» - север, «З» - запад, «Ю» - юг, «В» - восток. Число 1 - поворот налево, –1 - поворот направо, 2 - поворот на 180 градусов")
a = ['С', 'З', 'Ю', 'В']
b = input("Введите исходное направление робота(С, З, Ю, В): ")
c = int(input("Введите число поворота(0, 1, 2): "))
print(f"     Ответ: {a[(a.index(b)+c) % 4]}", end='\n'*2)

#дз1
print('ДЗ1. Сумма и произведение цифр в числе. Было выше')

#дз2
print("ДЗ3. Число - abc, получить - acb")
print(f"     Ответ: {(a:=int(input('Введите число: ')))//100*100 + a%10*10 + a%100//10}", end='\n'*2)

#дз3
print("ДЗ3. Из цифр трёхзначного числа составить максимальное число")
a = input("Введите число: ")
mx = -10
mn = 10
average = None
for i in a:
    if int(i) > mx:
        mx = int(i)
    if int(i) < mn:
        mn = int(i)
for i in a:
    if int(i) != mx and int(i) != mn:
        average = i
print(f"     Ответ: {int(str(mx) + str(average) + str(mn))}", end='\n'*2)

#дз4
print("ДЗ4. Определить номер столетия по году")
a = input("Введите число: ")
if int(a) % 100 > 0:
    if len(a) == 4:
        print(f"     Ответ: {int(a[:2])+1} век", end='\n'*2)
    elif len(a) == 3:
        print(f"     Ответ: {int(a[0]) + 1} век", end='\n'*2)
    else:
        print(f"     Ответ: {1} век", end='\n'*2)
else:
    if len(a) == 4:
        print(f"     Ответ: {int(a[:2])} век", end='\n'*2)
    elif len(a) == 3:
        print(f"     Ответ: {int(a[0])} век", end='\n'*2)
    else:
        print(f"     Ответ: {-1} век", end='\n'*2)

#дз5
print("ДЗ5. Число палиндром?")
print(f"     Ответ: {(a:=input('Введите число: ')) == a[::-1]}", end='\n'*2)

#дз6
print("ДЗ6. Конь может попасть из 1-ой клетки во 2-ую. Было выше.", end='\n'*2)

#дз7
print("ДЗ7. Слон может сходить из 1-ой клетки во 2-ую.")
x1, y1, x2, y2 = int(input("Введите х1[1,8]: ")), int(input("Введите y1[1,8]: ")), int(input("Введите х2[1,8]: ")), int(input("Введите y2[1,8]: "))
dx, dy = abs(x1 - x2), abs(y1 - y2)
print(f"     Ответ: {dx == dy}", end='\n'*2)

#дз8
print("ДЗ8. Определить порядковый номер уникального числа в последовательности, в которой два числа из трёх равны")
a, b, c = int(input("Введите 1-ое число: ")), int(input("Введите 2-ое число: ")), int(input("Введите 3-ое число: "))
print(f"     Ответ: {1 if b==c else 2 if a == c else 3} число", end='\n'*2)

#дз9
print("ДЗ9. Задача, аналогичная ДЗ8. В задании они были одинаковы.", end='\n'*2)

#дз10
print("ДЗ10. Вывести строку-описание числа вида 'положит./отрицат./нулевое чётное/нечётное/- число'")
n = int(input("Введите число: "))
a = ['отрицательное', 'положительное']
b = ['чётное', 'нечётное']
print(f"    Ответ: {'нулевое число' if n == 0 else a[n>0] + ' ' + b[n%2] + ' число'}", end='\n'*2)