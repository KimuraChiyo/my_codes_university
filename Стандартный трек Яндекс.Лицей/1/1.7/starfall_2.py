n = input()
flag = False
count = 1
number = 0

while n != 'ВСЁ':
    if 'звезд' in n or 'Звезд' in n:
        if number == 0:
            number = count
        flag = True
    count += 1
    n = input()

if flag:
    print(number)
else:
    print('НЕТ')