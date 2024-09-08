num = int(input())
number = 0

while num > 0:
    number = num % 12
    num //= 12

print(number)