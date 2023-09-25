intersects = []
fields = ''
inputs = input()
while inputs != '':
    intersects.append(inputs)
    arr, place = inputs
    if arr not in fields:
        fields += arr
    if place not in fields:
        fields += place
    inputs = input()
print(' '.join(sorted(' ' + fields)))
fields = ''.join(sorted(fields))
field = [[i] for i in fields]
for row in field:
    row.extend([0 for i in range(len(fields))])
for intersect in intersects:
    arr, place = intersect
    arr, place = fields.index(arr), fields.index(place) + 1
    field[arr][place] = 1
[print(*row) for row in field]
