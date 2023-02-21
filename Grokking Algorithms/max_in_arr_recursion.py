def max(list):
    if len(list) == 0:
        return 0
    elif len(list) == 1:
        return list[0]
    else:
        max_in_other = max(list[1:])
        return list[0] if max_in_other < list[0] else max(list[1:])

arr = [1, 4, 2, 134, 1, 2, 4, 0]

print(max(arr))