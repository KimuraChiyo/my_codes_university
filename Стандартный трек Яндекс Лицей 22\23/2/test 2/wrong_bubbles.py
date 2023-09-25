count_strings = int(input())
dictionary = {}
for i in range(1, count_strings + 1):
    row = list(map(int, input().split()))
    elem_secondary_diag = row[count_strings - i]
    other = row[:count_strings - i] + row[count_strings - i + 1:]
    if elem_secondary_diag not in dictionary:
        dictionary[elem_secondary_diag] = other
    else:
        dictionary[elem_secondary_diag].extend(other)
for key, arr in dictionary.items():
    dictionary[key] = sorted(set(arr), reverse=True)
print(dictionary)