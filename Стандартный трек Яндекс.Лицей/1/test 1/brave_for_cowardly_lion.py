a, b, c = map(int, input())
if (a * c) % 6 == 0 and b != 7:
    print('Не трус')
else:
    print(a * c, b)