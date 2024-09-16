def is_valid(jrnl, num):
    cpy = jrnl[:]
    while -1 in cpy:
        cpy.remove(-1)
    return len(jrnl) == num and sorted(cpy) == cpy 

def restore(jrnl):
    rest = []
    last_mean = 0
    to_rest = 0
    for i in range(len(jrnl)):
        if jrnl[i] != -1:
            if to_rest:
                diff = jrnl[i] - last_mean
                step = int(diff / (to_rest + 1))
                rest.extend(list(range(last_mean, last_mean + step * to_rest + 1, step))[1:])
                to_rest = 0
            rest.append(jrnl[i])
            last_mean = jrnl[i]
        else:
            to_rest += 1
            if i == (len(jrnl) - 1):
                step = rest[len(rest) - 1] - rest[len(rest) - 2] + 1 if len(rest) >= 2 else 1
                rest.extend(list(range(last_mean, last_mean + step * to_rest + 1, step))[1:])
    return rest

def diffs(rest):
    rest = [0] + rest
    return [rest[i] - rest[i - 1] for i in range(1, len(rest))]


n, jrnl = int(input()), list(map(int, input().split()))
print('YES\n' + ' '.join(map(str, diffs(restore(jrnl)))) if is_valid(jrnl, n) else 'NO')

# YES
# 1 2 3 4 5
'''
5
1 3 -1 10 -1
'''

# NO
'''
3
10 -1 4
'''