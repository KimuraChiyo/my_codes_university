first = len(input())
second = len(input())
third = len(input())
step = min(first, min(second, third))
start = max(first, max(second, third))
end = first + second + third - step - start
for i in range(start, end - 1, -step):
    print(i, end=' ')