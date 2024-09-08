from math import sqrt

def function(x):
    return x**3 / ((1 - x**2)**0.5)

def left(func, a, b, n):
    h = (b - a) / n
    res = 0
    start = a
    for i in range(n):
        res += func(start + i * h) * h
    return round(res, 5)

def middle(func, a, b, n):
    h = (b - a) / n
    res = 0
    start = a + 0.5 * h
    for i in range(n):
        res += func(start + i * h) * h
    return round(res, 5)

def right(func, a, b, n):
    h = (b - a) / n
    res = 0
    start = a + h
    for i in range(n):
        res += func(start + i * h) * h
    return round(res, 5)

a = -0.5
b = 0.5
n = 10

print('Левые прямоугольники: ', left(function, a, b, n))
print('Средние прямоугольники: ', middle(function, a, b, n))
print('Правые прямоугольники: ', right(function, a, b, n))
