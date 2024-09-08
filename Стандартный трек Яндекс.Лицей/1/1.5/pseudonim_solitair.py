count = int(input())

while count > 0:
    step = int(input())
    if 0 < step < 4 and step <= count:
        count -= step
    print(count)
