import sys


def count_divs(x):
    d = set()
    for i in range(1, int(x ** 0.5) + 1):
        if x % i == 0:
            d |= {i, x // i}
    return len(d)


print(sorted([(int(i), count_divs(int(i))) for i in sys.stdin], key=lambda x: (x[1], x[0]))[1:])
