bin_tree = list()
row = list(map(int, input().split()))
while len(row) != 1:
    bin_tree.append(row[:])
    if len(row) % 2:
        row.append(0)
    row = [row[i] + row[i + 1] for i in range(0, len(row), 2)]
bin_tree.append(row)
for i in bin_tree[::-1]:
    print(*i)