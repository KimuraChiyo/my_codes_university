a = [[0] * 10 for i in range(10)]
ships = [4, 3, 3, 2, 2, 2, 1, 1, 1, 1]
curr_ship = 0
for i in range(1, 5):
    count_of_ships = i
    while count_of_ships > 0:
        string = input()
        place, layout = string[:string.index(' ')], string[string.index(' ') + 1:]
        field, arr = 'абвгдежзик'.index(place[0]), int(place[1:]) - 1
        for i in range(ships[curr_ship]):
            if layout == 'в':
                a[arr + i][field] = '\u25A1'
            if layout == 'г':
                a[arr][field + i] = '\u25A1'
        curr_ship += 1
        count_of_ships -= 1
[print(*row) for row in a]

