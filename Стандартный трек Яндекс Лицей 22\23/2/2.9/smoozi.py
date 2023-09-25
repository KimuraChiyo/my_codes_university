resources = {}
for i in range(5):
    position = input()
    resource = position[:position.index(':')]
    count = int(position[position.rindex(' ') + 1:])
    resources[resource] = count
    
res_for_orders = {'Сладкоежка': ['банан', 'молоко', 'мороженое'],
                  'Клубнично-банановый': ['клубника', 'молоко', 'банан', 'мороженое'],
                  'Клубничный': ['клубника', 'молоко', 'мороженое'],
                  'Хушаф': ['финики', 'молоко'],
                  'Банановый': ['банан', 'молоко', 'финики']}

count_orders = int(input())
for i in range(count_orders):
    order = input()
    # needful resources
    need_res = res_for_orders[order]
    # checking resources
    flag = True
    for resource in need_res:
        if resources[resource] < 1:
            flag = False
    # flag = resources enough
    if flag:
        print(f"Пожалуйста, ваш {order}. Приятного аппетита!")
        # -1 for every resource, which was needful
        for resource in need_res:
            resources[resource] -= 1
    else:
        print('Извините, не можем выполнить заказ.')
