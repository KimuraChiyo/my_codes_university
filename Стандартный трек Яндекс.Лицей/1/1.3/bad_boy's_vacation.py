first_city = input()
second_city = input()

if first_city != second_city:
    if (first_city == 'Тула' and second_city != 'Пенза') or (first_city != 'Тула' and second_city == 'Пенза'):
        print('ДА')
    else:
        print('НЕТ')
else:
    print('НЕТ')