n = int(input())
m = int(input())
if n % m:
    b = n // m + 1
else:
    b = n // m
print(b)