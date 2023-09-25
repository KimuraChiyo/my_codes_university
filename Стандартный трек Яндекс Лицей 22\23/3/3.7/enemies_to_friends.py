def friend_name(x):
    last_name = x.split()[-1]
    if last_name.endswith('ino'):
        last_name = last_name[:-3] + 'lone'
    else:
        last_name = last_name[:-2] + 'ino'
    return last_name


enemies = list(filter(lambda x: len(x.split()) > 1, input().split('; ')))
print(', '.join(list(map(friend_name, enemies))))
