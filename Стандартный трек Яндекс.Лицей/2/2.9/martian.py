count_res = int(input())
all_res = {}
res_per_day = {}
for i in range(count_res):
    position = input()
    res = position[:position.index(' ')]
    count = int(position[position.rindex(' ') + 1:])
    all_res[res] = count

for i in range(count_res):
    position = input()
    res = position[:position.index(' ')]
    count = int(position[position.rindex(' ') + 1:])
    res_per_day[res] = count

count_min = 10**200
for i in all_res.keys():
    count = 0
    while all_res[i] >= res_per_day[i]:
        all_res[i] -= res_per_day[i]
        count += 1
    if count <= count_min:
        count_min = count
    # print(f"key: {i}, count_days: {count}")
print(count_min)
