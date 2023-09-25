one = int(input())
two = int(input())
three = int(input())
four = int(input())
five = int(input())

mx = one
print(1, end=' ')

if mx < two:
    print(2, end=' ')
    mx = two

if mx < three:
    print(3, end=' ')
    mx = three

if mx < four:
    print(4, end=' ')
    mx = four

if mx < five:
    print(5, end=' ')