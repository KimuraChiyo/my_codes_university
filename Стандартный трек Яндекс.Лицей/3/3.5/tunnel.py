def tunnel(mass):
    if len(mass) > 2:
        return tunnel(mass[1:len(mass) - 1])
    else:
        return sum(mass)