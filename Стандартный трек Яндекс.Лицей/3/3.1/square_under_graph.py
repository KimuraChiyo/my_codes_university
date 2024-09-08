def square(data):
    summ = 0
    for value in data:
        a, b, h = value
        summ += h * (a + b) / 2
    print(summ)

# data = [(5, 3, 2), (3, 0, 6), (0, 12, 4), (12, 7, 3), (7, 7, 2)]
# square(data)
