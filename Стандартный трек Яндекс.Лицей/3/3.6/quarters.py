def quarters(*args):
    dct = {'I': 0, 'II': 0, 'III': 0, 'IV': 0}
    for dot in args:
        x, y = dot
        if x > 0:
            if y > 0:
                dct['I'] += 1
            elif y < 0:
                dct['IV'] += 1
        elif x < 0:
            if y > 0:
                dct['II'] += 1
            elif y < 0:
                dct['III'] += 1
    return dct
