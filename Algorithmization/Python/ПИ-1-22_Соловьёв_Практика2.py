# ПИ-1-22, Соловьёв Л.А.
from math import prod

#3.1
print("3.1. Вывод от 1 до 15")
print(*[i for i in range(1, 16)], sep = '  ', end = '\n\n')

#3.2
print("3.2. Вывод чётных чисел от 2 до 20")
print(*[i for i in range(2, 21, 2)], sep = '  ', end = '\n\n')

#3.3
print("3.3. Таблица перевода от 1 до 20 долларов в рубли")
print("     Ответ: ")
print(*[f"            {i}$ = {i*65} руб." for i in range(1, 21)], sep = '\n', end = '\n\n')

#3.4
print("3.4. Таблица  для вывода стоимости от 1 до 10кг конфет")
n = float(input("Введите стоимость 1кг. конфет: "))
print("     Ответ: ")
print(*[f"             | {i}кг. | {i*n}руб. |" for i in range(1, 11)], sep = '\n' + ' ' * 13 + 18 * '_' + '\n', end = '\n\n')

#3.5
print("3.5. Произведение первых ста чисел")
print(f"     Ответ: {prod([i for i in range(1, 100)])}", end = '\n\n')

#3.6
print("3.6. Среднее арифм. целых чисел от 1 до 100")
print(f"     Ответ: {sum([i for i in range(1, 101)]) / len([i for i in range(1, 101)])}", end = '\n\n')

#3.7
print("3.7. Сумма нечётных чисел от 1 до 99")
print(f"     Ответ: {sum([i for i in range(1, 100) if i % 2])}", end = '\n\n')

#3.8
print("3.8. Вычислить сумму чисел вида 1/k**5, где k - от 1 до n")
k, n = int(input("Введите k: ")), int(input("Введите n: "))
print('Через генератор:')
print(f"     Ответ: {sum([1/k**5 for k in range(1, n+1)])}")
print('Через рекурр. формулу:')
curr = 1
summ = curr
for i in range(2, n+1):
    curr = (curr * ((i-1)**5)) / (i**5)
    summ += curr
print(f"     Ответ: {summ}", end = '\n\n')

#3.9
print("3.9. Вычислить произведение чисел вида 1 + 1/k, где k - от 1 до n")
k, n = int(input("Введите k: ")), int(input("Введите n: "))
print('Через генератор:')
print(f"     Ответ: {prod([(1 + (1/k)) for k in range(1, n+1)])}")
print('Через рекурр. формулу:')
current = 2
prod = current
current -= 1
for i in range(2, n+1):
    current = ((current * (i-1)) / i)
    prod = prod * (1 + current)
print(f"     Ответ: {prod}", end = '\n\n')

#4.1
print("4.1. Вывести все целые числа между двумя числами")
a, b = int(input("Введите A: ")), int(input("Введите B(B > A): "))
print("     Ответ: ", end = '')
while a < b-1:
    a+=1
    print(a, end = '  ')


#4.2
print("\n\n4.2. Вывести все целые числа между двумя числами в порядке убывания")
a, b = int(input("Введите A: ")), int(input("Введите B(B > A): "))
print("     Ответ: ", end = '')
while b > a + 1:
    b-=1
    print(b, end = '  ')

#4.3
print("\n\n4.3. Задания не было", end = '\n'*2)

#4.4
print("4.4. Вывести все числа меньше n")
i = 0
n = int(input("Введите n: "))
print("     Ответ: ", end = '')
while i < n:
    print(i, end = '  ')
    i += 1

#4.5
print("\n\n4.5. Первое натуральное число, квадрат которого больше n")
i = 0
n = int(input("Введите n: "))
while i*i < n:
    i+=1
print(f"    Ответ: {i}", end = '\n\n')

#4.6
print("4.6. Произведение и количество нечетных цифр числа")
n = int(input("Введите число: "))
count = 0
prod = 1
while n > 0:
    if ((n%10)%2):
        count += 1
        prod *= (n%10)
    n //= 10
print(f"     Ответ: production = {prod} count = {count}", end = '\n\n')

#4.7
print("4.7. Сумма нечётных чисел от 1 до 99")
i = 1
summ = 0
while i < 100:
    if i%2:
        summ += i
    i += 1
print(f"     Ответ: {summ}", end = "\n\n")

#4.8
print("4.8. Сколько цифр в числе n?")
n = int(input("Введите число: "))
count = 0
while n > 0:
    count += 1
    n //= 10
print(f"     Ответ: {count}", end = "\n\n")

#4.9
print("4.9. Все целые числа до 200, где сумма цифр = 13")
i = 0
print("     Ответ: ", end = '')
while i < 201:
    curr_num = i
    summ = 0
    while i > 0:
        summ += i%10
        i //= 10
    if summ == 13:
        print(curr_num, end = '  ')
    i = curr_num + 11