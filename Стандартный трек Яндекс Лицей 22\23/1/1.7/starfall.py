n = input()
flag = False
while n != 'ВСЁ':
    if 'звезд' in n or 'Звезд' in n:
        flag = True
    n = input()

if flag:
    print('Загадывай!')
else:
    print('НЕТ')