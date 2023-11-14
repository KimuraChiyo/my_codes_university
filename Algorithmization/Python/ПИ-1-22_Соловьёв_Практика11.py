import os

# 1
def is_filename(name):
    try:
        f = open(name, 'r')
    except:
        return False
    return True

print("1. Дана строка S. Если S является допустимым именем файла, то создать пустой файл с этим именем и вывести True. Если файл с именем S создать нельзя, то вывести False.")
print(is_filename('.py!-cdnb'))

# 2
print('2. Дано имя файла и целое число N (> 1). Создать файл целых чисел с данным именем и записать в него N первых положительных четных чисел (2,4, …).')
filename, n = input('Введите имя файла: '), int(input('Введите n: '))
with open(filename, 'w') as f:
    lst = [2]
    while len(lst) != n:
        lst.append(lst[-1] + 2)
    f.write(' '.join(map(str, lst)))

# 3
print('3. Дано имя файла целых чисел. Найти количество элементов, содержащихся в данном файле. Если файла с таким именем не существует, то вывести –1.')
filename = input('Введите имя файла: ')
if filename in os.listdir():
    with open(filename, 'r') as f:
        count = len(f.readline().split())
        print(count)
else:
    print(-1)

# 4
print('4. Дан файл целых чисел, содержащий не менее четырех элементов. Вывести первый, второй, предпоследний и последний элементы данного файла.')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    print(file[0], file[1], file[-2], file[-1])

# 5
print('5. Дан файл целых чисел. Создать новый файл, содержащий те же элементы, что и исходный файл, но в обратном порядке.')
with open('file.txt', 'r') as f:
    file = f.readline()
with open('new_file.txt', 'w') as f:
    f.write(file)

# 6
print('6. Дан файл вещественных чисел. Создать два новых файла, первый из которых содержит элементы исходного файла с нечетными номерами (1, 3,…), а второй — с четными (2, 4, …).')
with open('file.txt', 'r') as f:
    file = f.readline().split()
with open('odds.txt', 'w') as odd:
    odd.write(' '.join(file[::2]))
with open('even.txt', 'w') as even:
    even.write(' '.join(file[1::2]))

# 7
print('7. Дан файл вещественных чисел. Заменить в нем все элементы на их квадраты.')
with open('file.txt', 'r') as f:
    file = map(lambda x: round(float(x) ** 2, 2), f.readline().split())
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 8
print('8. Дан файл вещественных чисел. Поменять в нем местами минимальный и максимальный элементы.')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    mx_index, mn_index = file.index(max(file)), file.index(min(file))
    file[mn_index], file[mx_index] = file[mx_index], file[mn_index]
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 9
print('9. Дан файл целых чисел, содержащий четное количество элементов. Удалить из данного файла вторую половину элементов.')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    file = file[:len(file) // 2]
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 10
print('10. Дан файл целых чисел. Удалить из него все элементы с четными номерами.')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    file = file[::2]
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 11
print('11. Дан файл целых чисел. Удалить из него все отрицательные числа.')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    file = filter(lambda x: float(x) >= 0, file)
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 12
print('12. Дан файл целых чисел. Удвоить его размер, записав в конец файла все его исходные элементы (в том же порядке).')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    file = file * 2
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 13
print('13. Дан файл целых чисел. Продублировать в нем все элементы с нечетными номерами.')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    i = 0
    while i < len(file):
        file.insert(i, file[i])
        i += 3
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 14
print('14. Дан файл целых чисел. Заменить в нем каждый элемент с четным номером на два нуля.')
with open('file.txt', 'r') as f:
    file = f.readline().split()
    i = 1
    while i < len(file):
        del file[i]
        file.insert(i, 0)
        file.insert(i, 0)
        i += 3
with open('file.txt', 'w') as f:
    f.write(' '.join(map(str, file)))

# 15
print('15. Даны два файла произвольного типа. Поменять местами их содержимое.')
with open('first.txt', 'r') as frst:
    first = frst.readlines()
with open('second.txt', 'r') as scnd:
    second = scnd.readlines()
with open('first.txt', 'w') as frst:
    frst.write(''.join(second))
with open('second.txt', 'w') as scnd:
    scnd.write(''.join(first))

# 16
print('16. Дан файл произвольного типа. Создать его копию с новым именем.')
with open('file.txt', 'r') as f:
    file = f.readlines()
with open('new_file.txt', 'w') as nf:
    nf.write(''.join(file))

# 17
print('17. Даны три файла одного и того же типа, но разного размера. Заменить содержимое самого длинного файла на содержимое самого короткого.')
with open('first.txt', 'r') as f:
    lines_first = f.readlines()
with open('second.txt', 'r') as f:
    lines_second = f.readlines()
with open('new_first.txt', 'r') as f:
    lines_third = f.readlines()
files = [lines_first, lines_second, lines_third]
mass = [len(i) for i in files]
mx_mass = mass.index(max(mass))
mn_mass = mass.index(min(mass))
names = ['first.txt', 'second.txt', 'new_first.txt']
with open(names[mx_mass], 'w') as f:
    f.write(''.join(files[mn_mass]))
with open(names[mn_mass], 'w') as f:
    f.write(''.join(files[mx_mass]))

# 18
print('18. Даны два файла одного и того же типа. Добавить к первому файлу содержимое второго файла, а ко второму файлу — содержимое первого.')
with open('first.txt', 'r') as f:
    lines_first = list(map(lambda x: x.strip(), f.readlines()))
with open('second.txt', 'r') as f:
    lines_second = list(map(lambda x: x.strip(), f.readlines()))
lines_first, lines_second = lines_first + lines_second, lines_second + lines_first
with open('first.txt', 'w') as f:
    f.write('\n'.join(lines_first))
with open('second.txt', 'w') as f:
    f.write('\n'.join(lines_second))

# 19
print('19. Дан файл целых чисел. Создать два новых файла, первый из которых содержит положительные числа из исходного файла (в обратном порядке), а второй — отрицательные (также в обратном порядке). Если положительные или отрицательные числа в исходном файле отсутствуют, то соответствующий результирующий файл оставить пустым.')
with open('ints.txt', 'r') as f:
    nums = list(map(int, f.readline().split()))
    nums_first = [i for i in nums[::-1] if i >= 0]
    nums_second = [i for i in nums[::-1] if i < 0]
with open('plus.txt', 'w') as f:
    f.write(' '.join(map(str, nums_first)))
with open('minus.txt', 'w') as f:
    f.write(' '.join(map(str, nums_second)))

# 20
print('20. Даны два файла вещественных чисел с именами S1 и S2, элементы которых упорядочены по возрастанию. Объединить эти файлы в новый файл с именем S3 так, чтобы его элементы также оказались упорядоченными по возрастанию.')
with open('s1.txt', 'r') as f:
    nums = list(map(float, f.readline().split()))
with open('s2.txt', 'r') as f:
    nums += list(map(float, f.readline().split()))
nums = sorted(nums)
with open('s3.txt', 'w') as f:
    f.write(' '.join(map(str, nums)))

# 21
print('21. Дан символьный файл, содержащий по крайней мере один символ пробела. Удалить все его элементы, расположенные после первого символа пробела, включая и этот пробел.')
with open('file.txt', 'r') as f:
    string = list(map(lambda x: x.strip().split(' '), f.readlines()))
    need_string = []
    for i in string:
        need_string.extend(i)
    need_string = need_string[0]
with open('file.txt', 'w') as f:
    f.write(need_string)

# 22
print('22. Даны имена четырех файлов. Найти количество файлов с указанными именами, которые имеются в текущем каталоге')
files_dir = os.listdir()
names = ['lisa', 'hui', 'privet', 'hi']
for name in names:
    print("Файлы с именем", name, "встречаются", len([i for i in files_dir if name in i]))