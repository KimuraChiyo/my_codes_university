food = {}


def total(data):
    global food
    for position in data:
        name = position[:position.rindex(' ')]
        kcal = float(position[position.rindex(' '):])
        if name in food.keys():
            food[name][0] += 1
        else:
            food[name] = [1, kcal]
    food = {key: value for key, value in sorted(food.items())}
    total = 0
    for name, arr in food.items():
        count = arr[0]
        kcal = arr[1]
        total += kcal * count
        print(' - '.join([name, str(count), str(round(kcal * count, 1))]), 'kCal')
    print('------')
    print(f'Total: {round(total, 1)} kCal')
    print()
