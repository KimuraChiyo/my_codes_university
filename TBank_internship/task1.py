a_b_array = list(map(lambda x: x.split('-'), input().split(',')))
result = []
for i in a_b_array:
    i = list(map(int, i))
    a = i[0]
    b = i[1] if len(i) > 1 else a
    result.extend(list(range(a, b+1)))
print(*result)

# 1 2 3 4 5 6 8 9 11
'''
1-6,8-9,11
'''