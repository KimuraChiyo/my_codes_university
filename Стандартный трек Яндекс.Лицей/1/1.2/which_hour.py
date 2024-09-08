fake_num = input()
if fake_num in '23,0,1,2,3,4':
    print('Ночь')
elif fake_num in '5,6,7,8,9,10':
    print('Утро')
elif fake_num in '11,12,13,14,15,16,17':
    print('День')
elif fake_num in '18,19,20,21,22':
    print('Вечер')
else:
    print('Ошибка')