#1
print("1. Квадраты всех чисел до n через формулу 2*i-1")
n = int(input("Введите число: "))
print(f"    Ответ: ", end = '')
itog = 0
for i in range(1, n + 1):
    itog += 2*i - 1
    print(itog, end = ' ')

print("\n\n2. Найти значение выражения 1.1-1.2+1.3 и т.д.")
s = 0
curr = -1
n = int(input("Введите количество членов последовательность(n>2): "))
for i in range(1, n+1):
    s += (curr * -1) * (1 + i * 0.1)
    curr *= -1
print(f"     Ответ: {s}", end = '\n'*2)

#3
print("3. Последовательность а1 = 1, а2 = 2, a3 = 3, ak = ak-1 + ak-2 - 2*ak-3")
a, b, c = 1, 2, 3
n = int(input("Введите количество членов[2, ...]: "))
print(f"    Ответ: ", end = '')
for i in range(1, n+1):
    if i == 1:
        print(a, end = ' ')
    elif i == 2:
        print(b, end = ' ')
    elif i == 3:
        print(c, end = ' ')
    else:
        a, b, c = b, c, a + b - 2 * c
        print(c, end = ' ')

#4
print("\n\n4. Вывести все целые числа от А до В включительно, каждое включено столько же раз, какого его значение")
a, b = int(input("Введите А(> 0): ")), int(input("Введите B(> 0): "))
print(f"    Ответ: ", end = '')
for i in range(a, b + 1):
    print(f'{i} '*i, end = '')

#5
print("\n\n5. Найти двойной факториал n")
n = int(input("Введите число: "))
res = 1
i = 0
while (n-i) >= 2:
    res *= (n-i)
    i += 2
print(f"    Ответ: {res}", end = '\n'*2)

#6
print('6. Дано число A. Вывести наибольшее число K для которого сумма 1/1 + 1/2 + ... + 1/K будет меньше А')
a = float(input("Введите число, большее 1: "))
summa = 0
last_summ = 0
k = 1
while summa < a:
    summator = 0
    for i in range(1, k+1):
        summator += 1/i
    last_summ = summa
    summa = summator
    k+=1
print(f"     Ответ: K: {k-1}, Сумма: {last_summ}\
      \n            К+1: {k}, Сумма: {summa}", end = '\n'*2)

#7
print("7. Определить является ли число n - числом Фиббоначи")
a, b, c = 1, 1, 2
n = int(input("Введите число: "))
print(a, b, c, end = ' ')
while c < n:
    a, b = b, c
    c = a + b
    print(c, end = ' ')
print(f"\n     Ответ: {c == n}", end = '\n'*2)

#8-12
print("8.-12. Номера отсутствовали.")

#13
def math_round(num):
    return int(num // 1 if num % 1 < 0.5 else num // 1 + 1)

print("\n13. Дано число N и набор из N вещ. чисел. Вывести округленные значения и их сумма")
n = int(input("Введите количество чисел в наборе: "))
lenght_of_block = n
summ = 0
while n > 0:
    a = float(input(f"Введите {lenght_of_block-n+1}-е число: "))
    summ += round(a)
    print(f"Округлённое значение {lenght_of_block-n+1}-ого числа: {math_round(a)}\tТекущая сумма: {summ}")
    n-=1
print(f"     Ответ: Сумма округлённых значений равна {summ}", end = '\n'*2)

#14
print("14. Дано число N и набор из N вещ. чисел. Вывести нечётные значения и их количество")
n = int(input("Введите количество чисел в наборе: "))
lenght_of_block = n
b = []
while n > 0:
    a = input(f"Введите {lenght_of_block-n+1}-е число: ")
    if int(a) % 2:
        b.append(a)
    n-=1
print(f"     Ответ: Нечётные числа последовательности - {' '.join([str(i) for i in b])}, их количество - {len(b)}", end = '\n'*2)

#15
print("15. Дано число N и набор из N целых чисел(могут повторяться). Вывести уникальные члены последовательности")
n = int(input("Введите количество чисел в наборе: "))
lenght_of_block = n
b = []
while n > 0:
    a = int(input(f"Введите {lenght_of_block-n+1}-е число: "))
    b.append(a)
    n -= 1
print(f"     Ответ: Все уникальные числа последовательности - {' '.join(sorted([str(i) for i in set(b)]))}", end = '\n'*2)

#16
print("16. В последовательности из N чисел находятся два нуля, вывести сумму чисел, между двумя последними нулями")
n = int(input("Введите количество чисел в наборе: "))
lenght_of_block = n
c = []
b = []
flag = False
summ = 0
while n > 0:
    a = int(input(f"Введите {lenght_of_block-n+1}-е число: "))
    if a != 0:
        summ += a
    elif a == 0 and n != lenght_of_block:
        b.append(summ)
        summ = 0
    c.append(a)
    n -= 1
print(f"     Ответ: Последовательность - {' '.join([str(i) for i in c])}\n            Сумма между двумя последними нолями равна {b[-1]}", end = '\n'*2)

#17
print("17. Даны K, N. К - кол-во наборов, N - кол-во чисел в наборе")
b = [[0, 1, 2, 3, 4], [0, 2, 4, 6, 8], [0, 4, 6, 8, 10], [-2, -1, 0, 1, 2], [-4, -2, 0, 2, 4]]
print("Список для контр.примера - ",b)
k = int(input("Введите К(контр.пример = 5): "))
n = int(input("Введите N(контр.пример = 5): "))
print("     Ответ: Порядковые номера двоек в наборах(0, если её нет) - ", end = '')
while k > 0:
    i = 0
    a = n
    while a > 0:
        if b[-k][-a] == 2:
            i = n - abs(-a) + 1
        a -= 1
    k -= 1
    print(i, end = ' ')

#18
print("\n\n18. Дано K наборов ненулевых чисел, завершением набора является число 0. Найти длину каждого и общую длину")
k = int(input("Введите К: "))
sum_len = -k
count = -1
while k > 0:
    n = None
    while n != 0:
        n = int(input("Введите число: "))
        sum_len += 1
        count += 1
    else:
        print(f"---------------------Длина данного набора - {count}")
        count = -1
        k -= 1
print(f"     Ответ: Суммарная длина всех наборов - {sum_len}", end = '\n'*2)

#19
print("19. Дано K наборов ненулевых чисел, завершением набора является число 0. Найти кол-во возрастающих наборов")
k = int(input("Введите К: "))
count = 0
flag = False
while k > 0:
    n = int(input("Введите число: "))
    while n != 0:
        c, n = n, int(input("Введите число: "))
        if c > n and n != 0:
            flag = True
    else:
        print("---------------------", "Возрастающий набор?", not flag)
        if not flag:
            count += 1
        flag = False
        k -= 1
print(f"     Ответ: Количество возрастающих наборов - {count}",  end = '\n'*2)

#20
print("20. Дано K наборов ненулевых чисел, завершением набора является число 0. Каждому набору присвоить число: -1 - убыв., 1 - возраст. 0 - неупорядоченный")
k = int(input("Введите К: "))
count = 0
flag = -2
while k > 0:
    n = int(input("Введите число: "))
    while n != 0:
        c, n = n, int(input("Введите число: "))
        if c < n and n != 0:
            flag = [1, 0, 1][flag]
            # if flag == -2:
            #     flag = 1
            # elif flag == -1:
            #     flag = 0
            # elif flag == 0:
            #     flag = 1
        elif c > n and n != 0:
            flag = [-1, 0, -1][flag]
            # if flag == -2:
            #     flag = -1
            # elif flag == 1:
            #     flag = 0
            # elif flag == 0:
            #     flag = -1
        elif c == n and n != 0:
            flag = 0
    else:
        print("---------------------", int(flag) if flag != -2 else 0)
        flag = 0
        k -= 1

#21
print("\n\n21. Определить является ли набор пилообразным")
k = int(input("Введите количество чисел( > 2): "))
b = [int(input("Введите число: ")) for i in range(k)]
c = b[0] < b[1]
d = [ [(b[i-1] < b[i] > b[i+1] if i%2 else b[i-1] > b[i] < b[i+1]) for i in range(1, k-1)] , [(b[i-1] > b[i] < b[i+1] if i%2 else b[i-1] < b[i] > b[i+1]) for i in range(1, k-1)] ][not c]

print(f"    Ответ: 0" if all(d) else f"    Ответ: Порядковый номер первого неправильного элемента - {d.index(False)+2}")
