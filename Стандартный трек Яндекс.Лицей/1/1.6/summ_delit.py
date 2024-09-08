num = int(input())
summ = 0
for i in range(1, num + 1):
    if num % i == 0:
        summ += i

print(summ)