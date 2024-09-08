def rounding(data: list[float]):
    summ_int = 0
    summ_float = 0
    for num in data:
        summ_float += num % 1
        summ_int += int(num)
    return summ_int, round(summ_float, 2)

# data = []
# print(rounding(data))