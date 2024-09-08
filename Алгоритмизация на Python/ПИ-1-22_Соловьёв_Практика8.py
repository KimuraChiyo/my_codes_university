# Соловьёв Л.А. ПИ-1-22
from random import randint

# 1
print("1. Дано целое число N (> 0). Сформировать и вывести целочисленный список размера N, содержащий N первых положительных нечетных чисел: 1, 3, 5, … .")
lst = []
i = 1
n = int(input("Введите количество чисел: "))
while len(lst) != n:
    if i % 2:
        lst.append(i)
    i += 1
print("    Ответ:", *lst, end='\n'*2)

# 2
print("2. Дано целое число N (> 1), а также первый член A и разность D арифметической прогрессии. Сформировать и вывести список размера N, содержащий N первых членов данной прогрессии: A, A +D, A + 2·D, A + 3·D, … .")
lst = []
i = 0
n = int(input("Введите количество чисел: "))
a, d = int(input("Введите первый член А: ")), int(input("Введите разность арифм.прогрессии: "))
while len(lst) != n:
    lst.append(a + i * d)
    i += 1
print("    Ответ:", *lst, end='\n'*2)

# 3
print("3. Даны целые числа N (> 2), A и B. Сформировать и вывести целочисленный список размера N, первый элемент которого равен A, второй равен B, а каждый последующий элемент равен сумме всех предыдущих")
n = int(input("Введите количество чисел: "))
a, b = int(input("Введите первый член А: ")), int(input("Введите второй член B: "))
lst = [a, b]
while len(lst) != n:
    lst.append(sum(lst))
print("    Ответ:", *lst, end='\n'*2)

# 4
print("4. Дан целочисленный список размера N. Вывести все содержащиеся в данном списке четные числа в порядке убывания их индексов, а также их количество K.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 500))
print("Для списка:", lst)
print("    Ответ: ", end=' ')
for i in lst[::-1]:
    if not i % 2:
        print(i, end=' ')
print("\n")

# 5
print("5. Дан список A ненулевых целых чисел размера 10. Вывести значение первого из тех его элементов AK, которые удовлетворяют неравенству AK < A10. Если таких элементов нет, то вывести 0.")
lst = []
for i in range(10):
    lst.append(randint(1, 500))
need_elem = 0
last = lst[-1]
print("Для списка:", lst)
for element in lst[:len(lst)-1]:
    if element < last:
        need_elem = element
        break
print("    Ответ:", need_elem, end="\n"*2)

# 6
print("6. Дан список размера N и целые числа K и L (1 < K ≤ L ≤ N). Найти сумму всех элементов списка, кроме элементов с номерами от K до L включительно.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 10))
k, l = int(input("Введите K: ")), int(input("Введите N: "))
print("Для списка:", lst)
print("    Ответ:", sum(lst[:k-1] + lst[l:]), end="\n"*2)

# 7
print("7. Дан целочисленный список размера N. Проверить, чередуются ли внем четные и нечетные числа. Если чередуются, то вывести 0, если нет, то вывести порядковый номер первого элемента, нарушающего закономерность.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 40))
bool_list = [False]
for i in range(1, n):
    bool_list.append(lst[i - 1] % 2 == lst[i] % 2)
print("Для списка:", lst)
print("    Ответ:", sum(bool_list) if sum(bool_list) == 0 else bool_list.index(True) + 1, end="\n"*2)

# 8
print("8. Дан список A размера N. Найти минимальный элемент из его элементов с четными номерами: A2, A4, A6, … .")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 60))
print("Для списка:", lst)
need_lst = [lst[i] for i in range(1, len(lst), 2)]
print("    Ответ:", min(need_lst), end="\n"*2)

# 9
print("9. Дан список размера N. Найти номера тех элементов списка, которые больше своего правого соседа, и количество таких элементов. Найденные номера выводить в порядке их возрастания.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 60))
print("Для списка:", lst)
print("    Ответ: Номера: ", end='')
count = 0
for i in range(n-1):
    if lst[i] > lst[i + 1]:
        count += 1
        print(i + 1, end=' ')
print("\n"," " * 9, "Их количество:", count, end='\n'*2)

# 10
print("10. Даны два списка A и B одинакового размера N. Сформировать новый список C того же размера, каждый элемент которого равен максимальному из элементов списков A и B с тем же индексом.")
a, b, c = [], [], []
n = int(input("Введите размер списков: "))
for i in range(n):
    num1, num2 = randint(1, 60), randint(1, 60)
    a.append(num1)
    b.append(num2)
    c.append(num1 + num2 - min(num1, num2))
print("Для списка а:", a)
print("Для списка b:", b)
print("    Ответ: Cписок:", c, end="\n"*2)

# 11
print("11. Дан целочисленный список A размера N. Переписать в новый целочисленный список B все четные числа из исходного списка (в том же порядке) и вывести размер полученного списка B и его содержимое.")
a, b = [], []
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 100)
    a.append(num1)
    if not num1 % 2:
        b.append(num1)
print("Для списка:", a)
print("    Ответ: Длина:", len(b))
print(" " * 10, "Cписок:", b, end="\n"*2)

# 12
print("12. Дан список A размера N. Сформировать два новых списка B и C: в список B записать все положительные элементы списка A, в списокC — все отрицательные (сохраняя исходный порядок следования элементов). Вывести вначале размер и содержимое списка B, а затем — размер и содержимое списка C.")
a, b, c = [], [], []
n = int(input("Введите размер списков: "))
for i in range(n):
    num1 = randint(-100, 100)
    a.append(num1)
    if num1 > 0:
        b.append(num1)
    else:
        c.append(num1)
print("Для списка:", a)
print("    Ответ: Длина B:", len(b))
print(" " * 10, "Cписок B:", b)
print(" " * 10, "Длина C:", len(c))
print(" " * 10, "Cписок C:", c, end="\n"*2)

# 13
print("13. Дан список A размера N и целое число K (1 ≤ K ≤ N). Преобразовать список, увеличив каждый его элемент на исходное значение элемента AK.")
a = []
n = int(input("Введите размер списка: "))
k = int(input("Введите К: "))
for i in range(n):
    a.append(randint(1, 100))
ak = a[k - 1]
print("Для списка:", a)
for i in range(n):
    a[i] += ak
print("    Ответ: Элемент:", ak)
print(" " * 10, "Cписок:", a, end="\n"*2)

# 14
print("14. Дан список размера N. Поменять местами его минимальный и максимальный элементы.")
a = []
n = int(input("Введите размер списка: "))
for i in range(n):
    a.append(randint(1, 100))
print("Для списка:", a)
mx, mn = max(a), min(a)
index_mx, index_mn = a.index(mx), a.index(mn)
print("Максимальный элемент:", mx)
print("Минимальный элемент:", mn)
a.remove(mx)
a.insert(index_mn, mx)
a.remove(mn)
a.insert(index_mx, mn)
print("    Ответ: Итоговый список:", a, end="\n"*2)

# 15
print("15. Дан список размера N (N — четное число). Поменять местами его первый элемент со вторым, третий — с четвертым и т. д.")
a = []
n = int(input("Введите размер списка: "))
for i in range(n):
    a.append(randint(1, 100))
print("Список до:", a)
for i in range(1, n, 2):
    a[i], a[i - 1] = a[i - 1], a[i]
print("Список после:", a, end="\n"*2)

# 16
print("16. Дан список размера N. Обнулить элементы списка, расположенные между его минимальным и максимальным элементами (не включая минимальный и максимальный элементы).")
a = []
n = int(input("Введите размер списка: "))
for i in range(n):
    a.append(randint(1, 100))
print("Список до:", a)
mx, mn = max(a), min(a)
index_mx, index_mn = a.index(mx), a.index(mn)
print("Максимальный элемент:", mx)
print("Минимальный элемент:", mn)
a = a[:min(index_mx, index_mn) + 1] + [0] * (abs(index_mx - index_mn) - 1) + a[max(index_mx, index_mn):]
print("Список после:", a, end="\n"*2)

# 17
print("17. Дан список размера N и целое число K (1 ≤ K ≤ N). Удалить из списка элемент с порядковым номером K.")
a = []
n = int(input("Введите размер списка: "))
k = int(input("Введите K: "))
for i in range(n):
    a.append(randint(1, 100))
print("Список до:", a)
del a[k - 1]
print("Список после:", a, end="\n"*2)

# 18
print("18. Дан список размера N и целые числа K и L (1 ≤ K < L ≤ N). Удалить из списка элементы с номерами от K до L включительно и вывести размер полученного списка и его содержимое.")
a = []
n = int(input("Введите размер списка: "))
k = int(input("Введите K: "))
l = int(input("Введите L: "))
for i in range(n):
    a.append(randint(1, 100))
print("Список до:", a)
print("Его размер:", len(a))
for ind in range(k, l + 1):
    del a[k - 1]
print("Список после:", a)
print("Его размер:", len(a), end="\n"*2)

# 19
print("19. Дан целочисленный список размера N. Удалить из списка все нечетные числа и вывести размер полученного списка и его содержимое.")
a = []
n = int(input("Введите размер списка: "))
for i in range(n):
    a.append(randint(1, 100))
print("Список до:", a)
print("Его размер:", len(a))
rev_count_of_odd = sum([not (i % 2) for i in a])
i = 0
while len(a) != rev_count_of_odd:
    if a[i] % 2:
        del a[i]
        i -= 1
    i += 1
print("Список после:", a)
print("Его размер:", len(a), end="\n"*2)

# 20
print("20. Дан целочисленный список размера N. Удалить из списка все соседние одинаковые элементы, оставив их первые вхождения.")
a = []
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 100)
    a.append(num1)
    a.append(num1)
    a.append(num1)
print("Список до:", a)
print("Его размер:", len(a))
rev_count = len(set(a))
i = 0
while len(a) != rev_count:
    if a[i] == a[i + 1]:
        del a[i + 1]
        i -= 1
    i += 1
print("Список после:", a)
print("Его размер:", len(a), end="\n"*2)

# ДЗ1
print("ДЗ1. Дан целочисленный список размера N. Вывести все содержащиеся в данном списке нечетные числа в порядке возрастания их индексов, а также их количество K.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 500))
print("Для списка:", lst)
print("    Ответ: Числа:", end=' ')
count = 0
for i in lst:
    if i % 2:
        count += 1
        print(i, end=' ')
print('\n' + 11 * ' ' + f'Их количество: {count}\n')

# ДЗ2
print("ДЗ2. Дан список A размера N (N — четное число). Вывести его элементы с четными номерами в порядке возрастания номеров: A2, A4, A6, …, AN. Условный оператор не использовать.")
n = int(input("Введите размер списка: "))
a = [randint(1, 500) for i in range(n)]
print("Для списка:", a)
print("    Ответ:", *[a[i] for i in range(1, len(a), 2)], end="\n"*2)

# ДЗ3
print("ДЗ3. Дан список размера N и целые числа K и L (1 ≤ K ≤ L ≤ N). Найти сумму элементов списка с номерами от K до L включительно.")
n = int(input("Введите размер списка: "))
k, l = int(input("Введите K: ")), int(input("Введите L: "))
lst = [randint(1, 500) for i in range(n)]
print("Для списка:", lst)
print("    Ответ:", sum(lst[k - 1:l]), end="\n"*2)

# ДЗ4
print("ДЗ4. Дан список размера N. Найти номер его первого локального минимума (локальный минимум — это элемент, который меньше любого из своих соседей).")
n = int(input("Введите размер списка: "))
loc_min = 0
lst = [randint(1, 500) for i in range(n)]
print("Для списка:", lst)
for i in range(1, n - 1):
    if lst[i - 1] > lst[i] < lst[i + 1]:
        loc_min = lst[i]
        break
print("    Ответ:", loc_min, end="\n"*2)

# ДЗ5
print("ДЗ5. Дан целочисленный список A размера N. Переписать в новый целочисленный список B того же размера вначале все элементы исходного списка с четными номерами, а затем — с нечетными: A2,A4, A6, …, A1, A3, A5, … . Условный оператор не использовать.")
n = int(input("Введите размер списка: "))
lst = [randint(1, 500) for i in range(n)]
print("Для списка:", lst)
b = []
for i in range(1, len(lst), 2):
    b.append(lst[i])
for i in range(0, len(lst), 2):
    b.append(lst[i])
print("    Ответ:", b, end="\n"*2)

# ДЗ6
print("ДЗ6. Даны два списка A и B размера 5, элементы которых упорядочены по возрастанию. Объединить эти списки так, чтобы результирующий список C (размера 10) остался упорядоченным повозрастанию.")
a, b, c = [], [], []
for i in range(5):
    a.append(randint(1, 100))
    b.append(randint(1, 100))
a.sort()
b.sort()
print("Для списка а:", a)
print("Для списка b:", b)
pointer_a, pointer_b = 0, 0
while len(a) != 0 or len(b) != 0:
    if len(a) != 0:
        mn_a = a.pop(pointer_a)
    else:
        mn_a = 101
    if len(b) != 0:
        mn_b = b.pop(pointer_b)
    else:
        mn_b = 101
    app = min(mn_b, mn_a)
    ins = max(mn_b, mn_a)
    c.append(app)
    if app == mn_a and ins != 101:
        b.insert(pointer_b, ins)
    elif app == mn_b and ins != 101:
        a.insert(pointer_a, ins)
print("    Ответ:", c, end="\n"*2)

# ДЗ7
print("ДЗ7. Дан список размера N. Осуществить сдвиг элементов списка влево на одну позицию (при этом AN перейдет в AN–1, AN–1 — в AN–2, …, A2 в A1, a исходное значение первого элемента будет потеряно). Последний элемент полученного списка положить равным 0.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 500))
print("Для списка:", lst)
for i in range(len(lst) - 1):
    lst[i] = lst[i + 1]
lst[-1] = 0
print("    Ответ:", lst, end="\n"*2)

print("Задачи Повышенной Сложности - ЗПС")

# ЗПС1
print("ЗПС1. Дан целочисленный список размера N. Найти максимальное количество его одинаковых элементов.")
lst = []
dct = {}
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 4))
print("Для списка:", lst)
for elem in set(lst):
    dct[elem] = lst.count(elem)
mx = max([(key, value) for key, value in dct.items()], key=lambda x: x[1])
flag = True
for tpl in dct.items():
    if tpl[1] == mx[1]:
        if flag:
            print("    Ответ: Количество одинаковых элементов:", mx[1])
            flag = False
        else:
            print("           Количество одинаковых элементов:", mx[1])
        print("           Элемент:", tpl[0])
print("\n")

# ЗПС2
print("ЗПС2. Дан список размера N (N — четное число). Поменять местамипервую и вторую половины списка")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    lst.append(randint(1, 100))
print("Для списка:", lst)
print("    Ответ:", lst[len(lst)//2:] + lst[:len(lst)//2], end="\n"*2)

# ЗПС3
print("ЗПС3. Дан список A размера N и целое число K (1 ≤ K ≤ 4, K < N). Осуществить циклический сдвиг элементов списка вправо на K позиций (при этом A1 перейдет в AK+1, A2 — в AK+2, …, AN — в AK). Допускается использовать вспомогательный список из 4 элементов.")
lst = []
n = int(input("Введите размер списка: "))
k = n - int(input("Введите K: "))
for i in range(n):
    lst.append(randint(1, 500))
print("Для списка:", lst)
print("    Ответ:", lst[k:] + lst[:k], end="\n"*2)

# ЗПС4
print("ЗПС4. Дан целочисленный список размера N. Удалить из списка все элементы, встречающиеся менее трех раз, и вывести размер полученного списка и его содержимое.")
lst = []
dct = {}
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 500)
    if i % 3 == 0:
        lst += [num1] * 3
    elif i % 3 == 1:
        lst += [num1] * 2
    elif i % 3 == 2:
        lst += [num1]
print("Для списка:", lst)
for elem in set(lst):
    dct[elem] = lst.count(elem)
for num, count in dct.items():
    if count < 3:
        while num in lst:
            lst.remove(num)
print("    Ответ:", lst, '\n' + 11 * ' ' + f'Длина списка: {len(lst)}',end="\n"*2)

# ЗПС5
print("ЗПС5. Дан целочисленный список размера N. Удалить из списка все одинаковые элементы, оставив их последние вхождения.")
lst = []
dct = {}
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 500)
    if i % 3 == 0:
        lst += [num1] * 3
    elif i % 3 == 1:
        lst += [num1] * 2
    elif i % 3 == 2:
        lst += [num1]
print("Для списка:", lst)
for elem in set(lst):
    dct[elem] = lst.count(elem)
for num, count in dct.items():
    while lst.count(num) != 1:
        lst.remove(num)
print("    Ответ:", lst, end="\n"*2)

# ЗПС6
print("ЗПС6. Дан целочисленный список размера N. Удалить из списка все элементы, встречающиеся ровно два раза, и вывести размер полученного списка и его содержимое.")
lst = []
dct = {}
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 500)
    if i % 3 == 0:
        lst += [num1] * 3
    elif i % 3 == 1:
        lst += [num1] * 2
    elif i % 3 == 2:
        lst += [num1]
print("Для списка c длиной ", len(lst), ": ", lst, sep='')
for elem in set(lst):
    dct[elem] = lst.count(elem)
for num, count in dct.items():
    if count == 2:
        while num in lst:
            lst.remove(num)
print("    Ответ: Длина итогового списка:", len(lst))
print("           Итоговый список:", lst, end="\n"*2)

# ЗПС7
print("ЗПС7. Дан список размера N. Вставить элемент с нулевым значениемперед минимальным и после максимального элемента списка.")
lst = []
dct = {}
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 500)
    lst += [num1]
print("Для списка:", lst)
mx, mn = max(lst), min(lst)
print("Максимальный элемент:", mx)
print("Минимальный элемент:", mn)
lst.insert(lst.index(mn), 0)
lst.insert(lst.index(mx) + 1, 0)
print("    Ответ:", lst, end="\n"*2)

# ЗПС8
print("ЗПС8. Дан список размера N. Продублировать в нем элементы с четными номерами (2, 4, …). Условный оператор не использовать.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 500)
    lst += [num1]
print("Для списка:", lst)
i = 2
for i in range(1, len(lst) + 1, 3):
    lst.insert(i + 1, lst[i])
print("    Ответ:", lst, end="\n"*2)

# ЗПС9
print("ЗПС9. Дан целочисленный список A размера N. Назовем серией группу подряд идущих одинаковых элементов, а длиной серии — количество этих элементов (длина серии может быть равна 1). Сформировать два новых целочисленных списка B и C одинаковогоразмера, записав в список B длины всех серий исходного списка, а в список C — значения элементов, образующих эти серии.")
lst = []
n = int(input("Введите размер списка: "))
for i in range(n):
    num1 = randint(1, 500)
    if i % 3 == 0:
        lst += [num1] * 3
    elif i % 3 == 1:
        lst += [num1] * 2
    elif i % 3 == 2:
        lst += [num1]
print("Для списка:", lst)
b, c = [], []
count = 0
prev = lst[0]
for i in range(len(lst)):
    if lst[i] == prev:
        count += 1
    elif lst[i] != prev:
        b.append(count)
        c.append(prev)
        prev = lst[i]
        count = 1
else:
    b.append(count)
    c.append(prev)
print("    Ответ: Cписок длин:", b)
print("           Cписок элементов серий:", c)