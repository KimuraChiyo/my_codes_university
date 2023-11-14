# ПИ-1-22 Соловьёв Леонид
from random import randint
from math import prod


def transposed(matrix):
    n = len(matrix)
    m = len(matrix[0])
    transp_matrix = []
    for i in range(m):
        transp_matrix.append([0] * n)
    for i in range(m):
        for j in range(n):
            transp_matrix[i][j] = matrix[j][i]
    return transp_matrix


# 1
print("1. Даны целые положительные числа M и N. Сформировать целочисленную матрицу размера M × N, у которой все элементы I- й строки имеют значение 10*I (I = 1, …, M).")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[i * 10] * n for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()

# 2
print("2. Даны целые положительные числа M и N. Сформировать целочисленную матрицу размера M × N, у которой все элементы J- го столбца имеют значение 5*J (J = 1, …, N).")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[5*j for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()

# 3
print("3. Даны целые положительные числа M, N, число D и набор из M чисел. Сформировать матрицу размера M × N, у которой первый столбец совпадает с исходным набором чисел, а элементы каждого следующего столбца равны сумме соответствующего элемента предыдущего столбца и числа D (в результате каждая строка матрицы будет содержать элементы арифметической прогрессии).")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
d = int(input("Введите d: "))
row = [int(input("Введите " + str(i + 1) + " число: ")) for i in range(m)]
matrix = []
for i in range(n):
    matrix.append(row)
    row = [i + d for i in row]
matrix = transposed(matrix)
[print(*row, sep='\t') for row in matrix]
print()

# 4
print("4. Дана матрица размера M × N и целое число K (1 ≤ K ≤ M). Вывести элементы K-й строки данной матрицы.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
k = int(input("Введите k: ")) - 1
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print(str(k + 1) + " строка:", *matrix[k], sep='\t', end='\n\n')

# 5
print("5. Дана матрица размера M × N и целое число K (1 ≤ K ≤ N). Вывести элементы K-го столбца данной матрицы.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
k = int(input("Введите k: ")) - 1
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print(str(k + 1) + " столбец:", *[matrix[i][k] for i in range(len(matrix))], sep='\t', end='\n'*2)

# 6
print("6. Дана матрица размера M × N. Вывести ее элементы, расположенныев строках с четными номерами (2, 4, …). Вывод элементов производить по строкам, условный оператор не использовать.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
[print(*matrix[row], sep='\t') for row in range(1, len(matrix), 2)]

# 7
print("\n7. Дана матрица размера M × N. Вывести ее элементы, расположенныев столбцах с нечетными номерами (1, 3, …). Вывод элементов производить по столбцам, условный оператор не использовать.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
[print(*[row[i - 1] for i in range(1, len(row) + 1, 2)], sep='\t') for row in matrix]

# 8
treug = [[1]]
print("\n8. Треугольник Паскаля. Вывести на экран треугольник Паскаля из n строк. Придумать структуру данных для хранения треугольника Паскаля (например, стандартная матрица, что, однако, не экономно). Реализовать показ треугольника по данным из этой структуры.")
n = int(input("Введите число строк: "))
while len(treug) != n:
    last = [0] + treug[-1] + [0]
    new = []
    for i in range(len(last) - 1):
        new.append(last[i] + last[i + 1])
    treug.append(new)
[print(*row) for row in treug]

# 9
print("\n9. Дана матрица размера M × N и целое число K (1 ≤ K ≤ M). Найти сумму и произведение элементов K-й строки данной матрицы.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
k = int(input("Введите k: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
print("Сумма:", sum(matrix[k - 1]), "\nПроизведение:", prod(matrix[k - 1]))

# 10
print("\n10. Дана матрица размера M × N и целое число K (1 ≤ K ≤ N). Найти сумму и произведение элементов K-го столбца данной матрицы.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
k = int(input("Введите k: ")) - 1
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
print("Сумма:", sum([matrix[i][k] for i in range(len(matrix))]), "\nПроизведение:", prod([matrix[i][k] for i in range(len(matrix))]))

# 11
print("\n11. Дана матрица размера M × N. В каждой строке матрицы найти минимальный элемент.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
[print("Минимум строки " + str(i + 1) + ":", min(matrix[i])) for i in range(len(matrix))]

# 12
print("\n12. Дана матрица размера M × N. В каждом столбце матрицы найти максимальный элемент.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
[print("Максимум столбца " + str(i + 1) + ":", max([matrix[k][i] for k in range(len(matrix))])) for i in range(len(matrix[1]))]

# 13
print("\n13. Дана матрица размера M × N. Найти максимальный среди минимальных элементов ее строк.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
[print("Минимум строки " + str(i + 1) + ":", min(matrix[i])) for i in range(len(matrix))]
print("\nМаксимум минимумов:",  max([min(matrix[i]) for i in range(len(matrix))]))

# 14
print("\n14. Дана целочисленная матрица размера M × N. Найти элемент, являющийся максимальным в своей строке и минимальным в своем столбце. Если такой элемент отсутствует, то вывести 0.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, n + 1) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
mins = [min([matrix[k][i] for k in range(len(matrix))]) for i in range(len(matrix[1]))]
maxes = [max(row) for row in matrix]
need_elem = 0
ind_row = 0
ind_pos = 0
for i in range(m):
    mx = max(matrix[i])
    indexes = [index for index in range(n) if matrix[i][index] == mx]
    for elem in indexes:
        mn = min([matrix[i][elem] for i in range(m)])
        if matrix[i][elem] == mn:
            need_elem = matrix[i][elem]
            ind_pos = elem
            ind_row = i
if need_elem != 0:
    print("    Ответ:")
    print(10 * ' ' + "Нужный элемент:",need_elem, "\n" + 10 * ' ' + "Строка: ", ind_row + 1, "\n" + 10 * " " + "Позиция: ", ind_pos + 1)
else:
    print("    Ответ: 0")

# 15
print("\n15. Дана матрица размера M × N и целые числа K1 и K2 (1 ≤ K1 < K2 ≤ M). Поменять местами строки матрицы с номерами K1 и K2.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
k, l = int(input("Введите k: ")) - 1, int(input("Введите l: ")) - 1
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
matrix[k], matrix[l] =matrix[l], matrix[k]
[print(*row, sep='\t') for row in matrix]

# 16
print("\n16. Дана матрица размера M × N и целые числа K1 и K2 (1 ≤ K1 < K2 ≤ N). Поменять местами столбцы матрицы с номерами K1 и K2.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
k, l = int(input("Введите k: ")) - 1, int(input("Введите l: ")) - 1
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
for i in range(len(matrix)):
    matrix[i][k], matrix[i][l] =matrix[i][l], matrix[i][k]
[print(*row, sep='\t') for row in matrix]

# 17
print("\n17. Дана матрица размера M × N. Преобразовать матрицу, поменяв местами минимальный и максимальный элемент в каждой строке.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
for i in range(len(matrix)):
    mx_ind, mn_ind = matrix[i].index(max(matrix[i])), matrix[i].index(min(matrix[i]))
    matrix[i][mx_ind], matrix[i][mn_ind] = matrix[i][mn_ind], matrix[i][mx_ind]
[print(*row, sep='\t') for row in matrix]

# 18
print("\n18. Дана матрица размера M × N. Преобразовать матрицу, поменяв местами минимальный и максимальный элемент в каждом столбце.")
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 100) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
matrix = transposed(matrix)
for i in range(len(matrix)):
    mx_ind, mn_ind = matrix[i].index(max(matrix[i])), matrix[i].index(min(matrix[i]))
    matrix[i][mx_ind], matrix[i][mn_ind] = matrix[i][mn_ind], matrix[i][mx_ind]
matrix = transposed(matrix)
[print(*row, sep='\t') for row in matrix]

# 18
print("\n19. Дана квадратная матрица A порядка M. Найти сумму элементов ее главной диагонали, то есть диагонали, содержащей следующие элементы: A1,1, A2,2, A3,3, …, AM,M.")
m = int(input("Введите m: "))
matrix = [[randint(1, m + 1) for j in range(m)] for i in range(m)]
[print(*row, sep='\t') for row in matrix]
summ = 0
for i in range(m):
    summ += matrix[i][i]
print("    Ответ:", summ)

print('\n20. Дана квадратная матрица A порядка M. Найти среднее арифметическое элементов ее побочной диагонали, то есть диагонали, содержащей следующие элементы: A1,M, A2,M–1, A3,M–2, …, AM,1')
m = int(input("Введите m: "))
matrix = [[randint(1, m + 1) for j in range(m)] for i in range(m)]
[print(*row, sep='\t') for row in matrix]
arr = []
for i in range(m):
    arr.append(matrix[i][m-i-1])
print(f"    Ответ: ({' + '.join(map(str, arr))})[{sum(arr)}] / {len(arr)} = {sum(arr) / len(arr)}")

# 21
print('\n21. Дана квадратная матрица A порядка M. Найти сумму элементов каждой ее диагонали, параллельной главной (начиная с одноэлементной диагонали A1,M).')
m = int(input("Введите m: "))
matrix = [[randint(1, m + 1) for j in range(m)] for i in range(m)]
[print(*row, sep='\t') for row in matrix]
print()
diagons = []
for i in range(m - 1, 0, -1):
    diagon = []
    x = m - i
    y = 0
    while len(diagon) != i:
        diagon.append(matrix[y][x])
        y += 1
        x += 1
    diagons.append(diagon)
diagons = diagons[::-1]
for i in range(m - 1, 0, -1):
    diagon = []
    x = m - i
    y = 0
    while len(diagon) != i:
        diagon.append(matrix[x][y])
        y += 1
        x += 1
    diagons.append(diagon)
for diag in diagons:
    print(sum(diag))

# 22
print('\n22. Дана квадратная матрица A порядка M. Найти минимальный элемент для каждой ее диагонали, параллельной главной (начиная с одноэлементной диагонали A1,M).')
m = int(input("Введите m: "))
matrix = [[randint(1, m + 1) for j in range(m)] for i in range(m)]
[print(*row, sep='\t') for row in matrix]
print()
diagons = []
for i in range(m - 1, 0, -1):
    diagon = []
    x = m - i
    y = 0
    while len(diagon) != i:
        diagon.append(matrix[y][x])
        y += 1
        x += 1
    diagons.append(diagon)
diagons = diagons[::-1]
for i in range(m - 1, 0, -1):
    diagon = []
    x = m - i
    y = 0
    while len(diagon) != i:
        diagon.append(matrix[x][y])
        y += 1
        x += 1
    diagons.append(diagon)
for diag in diagons:
    print(min(diag))

# 23
print('\n23.Дана целочисленная матрица размера M × N. Найти номер последней из ее строк, содержащих только четные числа. Если таких строк нет, то вывести 0.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 4) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
flag = 0
for i in range(m):
    if all(map(lambda x: not x % 2, matrix[i])):
        flag = i + 1
print(flag)

# 24
print('\n24. Дана целочисленная матрица размера M × N. Найти количество ее строк, все элементы которых различны.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(1, 10) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
count = 0
for i in range(m):
    if len(set(matrix[i])) == len(matrix[i]):
        count += 1
print(count)

# 25
print('\n25. Дана матрица размера M × N. Поменять местами строки, содержащие минимальный и максимальный элементы матрицы. ')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
spec = []
for i in range(m):
    spec.extend(matrix[i])
mn_index = spec.index(min(spec))
mx_index = spec.index(max(spec))
print()
matrix[mn_index // m], matrix[mx_index // m] = matrix[mx_index // m], matrix[mn_index // m]
[print(*row, sep='\t') for row in matrix]

# 26
print('\n26. Дана матрица размера M × N. Поменять местами столбцы, содержащие минимальный и максимальный элементы матрицы.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
spec = []
for i in range(m):
    spec.extend(matrix[i])
mn_index = spec.index(min(spec))
mx_index = spec.index(max(spec))
print()
for i in range(m):
    matrix[i][mn_index % n], matrix[i][mx_index % n] = matrix[i][mx_index % n], matrix[i][mn_index % n]
[print(*row, sep='\t') for row in matrix]

# 27
print('\n27. Дана матрица размера M × N. Упорядочить ее строки так, чтобы их первые элементы образовывали возрастающую последовательность. ')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
[print(*row, sep='\t') for row in sorted(matrix, key=lambda x: x[0])]


# 28
print('\n28. Дана матрица размера M × N. Упорядочить ее столбцы так, чтобы их последние элементы образовывали убывающую последовательность.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
matrix = sorted(transposed(matrix), key = lambda x: -x[m - 1])
[print(*row, sep='\t') for row in transposed(matrix)]

# 29
print('\n29. Дана матрица размера M × N и целое число K (1 ≤ K ≤ M). Перед строкой матрицы с номером K вставить строку из нулей.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
k = int(input('Введите k: '))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
matrix.insert(k - 1, [0] * n)
[print(*row, sep='\t') for row in matrix]

# 30
print('\n30. Дана квадратная матрица порядка M. Обнулить элементы матрицы, лежащие ниже главной диагонали. Условный оператор не использовать.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
for i in range(m):
    matrix[i] = [0] * i + matrix[i][i:]
[print(*row, sep='\t') for row in matrix]

# 31
print('\n31. Дана квадратная матрица порядка M. Обнулить элементы матрицы, лежащие одновременно выше главной диагонали и выше побочной диагонали. Условный оператор не использовать.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
for i in range(1, m // 2 + 1):
    matrix[i - 1] = matrix[i - 1][:i] + [0] * (n - 2 * i) + matrix[i - 1][n - i:]
[print(*row, sep='\t') for row in matrix]

# 32
print('\n32. Дана квадратная матрица A порядка M. Зеркально отразить ее элементы относительно главной диагонали (при этом элементы главной диагонали останутся на прежнем месте, элемент A1,2 поменяется местами с A2,1, элемент A1,3 — с A3,1 и т. д.). Вспомогательную матрицу не использовать.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
for i in range(m):
    for j in range(i + 1, n):
        matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
print()
[print(*row, sep='\t') for row in matrix]

# 33
print('\n33. Дана квадратная матрица A порядка M. Повернуть ее на угол 90° в положительном направлении, то есть против часовой стрелки (при этом элемент A1,1 перейдет в AM,1, элемент AM,1 — в AM,M и т. д.). Вспомогательную матрицу не использовать.')
m, n = int(input("Введите m: ")), int(input("Введите n: "))
matrix = [[randint(100, 999) for j in range(1, n + 1)] for i in range(1, m + 1)]
[print(*row, sep='\t') for row in matrix]
print()
for i in range(3):
    matrix = transposed(matrix)
[print(*row, sep='\t') for row in matrix[::-1]]
