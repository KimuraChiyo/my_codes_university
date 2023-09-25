a = []

next_elem = int(input())
while abs(next_elem) < 1000:
    a.append(next_elem)
    next_elem = int(input())

print(sorted(a)[-2])