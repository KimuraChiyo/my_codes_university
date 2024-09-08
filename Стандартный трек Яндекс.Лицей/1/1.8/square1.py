s = int(input())
ss = ''
for i in range(int(s ** 0.5) + 1, 0, -1):
    if i * (s // i) == s and str(i) not in ss:
        ss += str(s // i)
        print(s // i, i)