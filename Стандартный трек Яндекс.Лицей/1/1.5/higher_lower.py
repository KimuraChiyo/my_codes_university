k, b = int(input()), int(input())
x = int(input())

count_down = 0
count_mid = 0
count_top = 0

while x != 'END':
    x = int(x)
    y = int(input())
    func_y = k * x + b
    if y > func_y:
        count_top += 1
    elif y == func_y:
        count_mid += 1
    else:
        count_down += 1
    x = input()

if count_top != 0:
    print('Выше прямой:', count_top)
if count_down != 0:
    print('Ниже прямой:', count_down)
if count_mid != 0:
    print('На прямой:', count_mid)