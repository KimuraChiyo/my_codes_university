count = int(input())
gen = 2
a, b = 1, 1
while b < count:
    a, b = b, a + b
    gen += 1
if b == count:
    print(gen)
else:
    print('НЕТ')