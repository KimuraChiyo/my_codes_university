a, b = int(input()), int(input())
count = 0

elem = int(input())

while elem != -1:
    if a < b and b > elem:
        count += 1
    a, b, elem = b, elem, int(input())
    
print(count)