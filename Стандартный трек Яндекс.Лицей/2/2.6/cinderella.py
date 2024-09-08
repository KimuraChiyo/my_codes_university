word = input()
print(*[i for i in input().split() if word in i])