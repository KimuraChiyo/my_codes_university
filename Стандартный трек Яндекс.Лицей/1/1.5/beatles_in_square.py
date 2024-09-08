from math import sqrt
lenght = float(input())
speed = float(input())
count = 0
while lenght - speed >= 0.01:
    count += 1
    lenght = sqrt((lenght - speed)**2 + speed**2)
print(count)