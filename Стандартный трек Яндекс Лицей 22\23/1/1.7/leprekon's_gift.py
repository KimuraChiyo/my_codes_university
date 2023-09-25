quality = 0
n = input()
last = 0
while len(n) > 0:
    if n == 'добрый':
        quality += 1
    elif n == 'злой':
        quality -= 1
    elif n == 'Какой подарок?':
        if quality > 0 and last == 'добрый':
            print('серебряный шиллинг')
            quality = 0
        elif quality < 0 and last == 'злой':
            print('золотой')
            quality = 0
        else:
            print('Ах, не знаю!')
            break
    last = n
    n = input()