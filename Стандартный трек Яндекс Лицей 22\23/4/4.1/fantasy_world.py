from random import randint, choice, randrange


def generate_fandom(n, names):
    lst = []
    used_ints = []
    for i in range(n):
        distance = randint(100, 500)
        while distance in used_ints:
            distance = randint(100, 500)
        used_ints.append(distance)
        name = choice(names)
        del names[names.index(name)]
        lst.append([name, randint(10, 20), randrange(10000, 1000000 + 1, 10000), distance])
    return lst
