def horse(start, end):
    fields = 'abcdefgh'
    start_x, start_y = fields.index(start[0]), int(start[1])
    end_x, end_y = fields.index(end[0]), int(end[1])
    dx, dy = abs(start_x - end_x), abs(start_y - end_y)
    if (dx == 2 and dy == 1) or (dx == 1 and dy == 2):
        flag = True
    else:
        flag = False
    print(flag)

# horse('f8', 'h7')
