# 1 фунт = 20 шиллингов = 240 пенсов = 960 фартингов
# 1 шиллинг = 12 пенсов = 48 фартингов
# 1 пенс = 4 фартинга

currency = input()
value = int(input())

if currency == 'пенс':
    value *= 4
    
if value // 960:
    print('Фунтов:', value // 960)
    value %= 960
if value // 48:
    print('Шиллингов:', value // 48)
    value %= 48
if value // 4:
    print('Пенсов:', value // 4)
    value %= 4
if value:
    print('Фартингов:', value)