n = int(input())
matrix = []
summ = 0
for _ in range(n):
    matrix.append(list(map(int, input().split(', '))))
for ind in range(n):
    summ += matrix[ind][ind] + matrix[ind][n - ind - 1]
    matrix[ind][ind], matrix[ind][n - ind - 1] = (
        matrix[ind][n - ind - 1], matrix[ind][ind])

for _ in matrix:
    print(*_)
print(summ)
