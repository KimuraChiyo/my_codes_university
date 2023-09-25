def power(x, p):
    if p == 0:
        return 1
    else:
        if p > 0:
            return x * power(x, p - 1)
        else:
            return (1 / x) * power(x, p + 1)

# print(power(5, -3))