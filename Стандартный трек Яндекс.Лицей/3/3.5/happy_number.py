def happy_number(n):
    x = str(n)
    if not x:
        return [0, 0]
    a, b = happy_number(x[1:-1])
    return [int(x[0]) + a, int(x[-1]) + b]