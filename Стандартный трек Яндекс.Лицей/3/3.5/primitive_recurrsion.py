def func(n):
    if n == 0:
        return 0
    elif n > 0 and n % 3 == 0:
        return func(n // 3) + 1
    elif n > 0 and n % 3:
        return func(n - 1) + 2

# print(func(10000))
