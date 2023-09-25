n = int(input())
for i in range(1, n ** 2 + 1):
    if i % n == 0:
        end = '\n'
    else:
        end = '\t'
    print(i, end=end)