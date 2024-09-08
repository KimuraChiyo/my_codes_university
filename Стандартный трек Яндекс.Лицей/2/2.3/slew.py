word = input()[::-1]
n = int(input())
m = int(input())
k = int(input())
if m == 0:
    m = 1
print(word[-n - 1:-m:k])
