cost = int(input())
count = 0

while cost > 1:
    count += 1
    cost /= 10
print(count)