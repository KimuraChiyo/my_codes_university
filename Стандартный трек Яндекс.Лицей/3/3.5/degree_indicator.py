def degree_indicator(p, x):
    if p == 1:
        return 0
    else:
        if p >= x:
            return degree_indicator(p // x, x) + 1
        else:
            return degree_indicator(p * x, x) - 1

# print(degree_indicator(1 / 625, 5))
