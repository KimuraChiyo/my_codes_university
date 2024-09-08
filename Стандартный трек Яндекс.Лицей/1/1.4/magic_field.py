x = 0
y = 0
count_left = 0
count_right = 0

action = input()
while action != 'СТОП':
    if action == 'шаг':
        curr_direct = count_left - count_right
        if abs(curr_direct) % 4 == 0:
            curr_direct = 0
        if curr_direct == -3:
            x -= 1
        elif curr_direct == -2:
            y -= 1
        elif curr_direct == -1:
            x += 1
        elif curr_direct == 0:
            y += 1
        elif curr_direct == 1:
            x -= 1
        elif curr_direct == 2:
            y -= 1
        elif curr_direct == 3:
            x += 1
    elif action == 'налево':
        count_left += 1
    elif action == 'направо':
        count_right += 1
    action = input()

print(x, y)