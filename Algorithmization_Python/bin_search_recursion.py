def bin_search(list, num):
    print(list)
    if len(list) == 0:
        return 0
    elif len(list) == 1:
        return True if list[0] == num else False
    else:
        mid = list[len(list) // 2]
        if mid < num:
            return bin_search(list[len(list) // 2:], num)
        elif mid == num:
            return True
        else:
            return bin_search(list[:len(list) // 2], num)

arr = [i for i in range(1, 101)]

print(bin_search(arr, 53))