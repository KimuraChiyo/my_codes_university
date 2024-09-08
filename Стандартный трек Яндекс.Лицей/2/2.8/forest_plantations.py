matrix = []
row = input()
while row != '':
    matrix.append(list(map(int, row.split(' : '))))
    row = input()
crit_value = int(input())

for row in matrix:
    print(*[(i if i >= crit_value else 0) for i in row], sep='\t')