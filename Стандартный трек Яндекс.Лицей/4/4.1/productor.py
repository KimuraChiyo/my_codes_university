from math import prod


def multiplier(*args, key=lambda x: x):
    lst = list(filter(key, args))
    return prod(lst) if len(lst) != 0 else None
