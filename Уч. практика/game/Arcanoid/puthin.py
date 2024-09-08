a = [1, 2, 3, 6, 7, 4, 4, 5]

flag = 0
sum = 0
for i in a:
    if i == 6 and not flag:
        flag = 1
    elif i == 7 and flag:
        flag = 0
    elif not flag:
        sum += i

print(sum)