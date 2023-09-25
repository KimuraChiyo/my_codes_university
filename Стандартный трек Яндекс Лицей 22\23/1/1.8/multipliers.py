n = int(input())
i = 2
print(n, end=' = ')
while n > 1:
    while n % i == 0:
        n //= i
        if n == 1:
            print(i)
        else:
            print(i, end=' * ')
    i += 1