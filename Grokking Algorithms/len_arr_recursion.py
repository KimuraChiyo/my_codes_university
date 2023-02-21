def len_of_arr(list):
    if len(list) == 0:
        return 0
    elif len(list) == 1:
        return 1
    else:
       return 1 + len_of_arr(list[1:])

arr = [i for i in range(1, 101)]

print(len_of_arr(arr))