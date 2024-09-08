start = int(input())
end = int(input())
step = int(input())
for i in range(start, end + 1, step):
    for j in range(start, end + 1, step):
        print(i, '+', j, '=', i + j, end='\t')
    print()
