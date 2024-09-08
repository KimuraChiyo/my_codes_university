start, end = map(int, input().split())
lst = sorted(range(end, start - 1, -1), key=lambda x: x % 2)
print(*filter(lambda x: x % 3 == 0, lst))
