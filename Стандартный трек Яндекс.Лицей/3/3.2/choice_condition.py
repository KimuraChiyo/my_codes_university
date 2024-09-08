def selection(arr: list[int], condition: int) -> list:
    a = []
    for num in arr:
        if num % condition == 0:
            a.append(num)
    return a

# data = [16, 17, 59, 2, 19]
# print(selection(data, 4))