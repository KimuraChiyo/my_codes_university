def is_valid(src, needed, pass_len):
    return not (len(src) < pass_len and any([i not in src for i in list(needed)]))

def password(src, needed, pass_len):
    res = -1
    for ind in range(len(src) - pass_len, -1, -1):
        if all([char in src[ind:ind+pass_len] for char in list(needed)]):
            res = src[ind:ind+pass_len]
            break
    return res

a = [input(),  input(), int(input())]
print(-1 if not is_valid(*a) else password(*a))

# caba
'''
abacaba
abc
4
'''

# cab
'''
abacaba
abc
3
'''