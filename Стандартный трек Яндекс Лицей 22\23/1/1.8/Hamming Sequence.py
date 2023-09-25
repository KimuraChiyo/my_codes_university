n = int(input())
number = 0
count = 0
k = 2
while count < n:
    num = k
    if num % 2 != 0 and num % 3 != 0 and num % 5 != 0:
        k += 1
        continue
    while num % 2 == 0:
        num //= 2
    while num % 3 == 0:
        num //= 3
    while num % 5 == 0:
        num //= 5
    if num == 1:
        count += 1
        number = k
    k += 1
print(number)
