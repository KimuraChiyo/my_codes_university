n = int(input())
s = 0
for i in range(1, n + 1):
    ss = 0
    if i % 2:
        for j in range(1, i + 1, 2):
            ss += j
    else:
        for j in range(2, i + 1, 2):
            ss += j
    s += i ** ss
print(s)