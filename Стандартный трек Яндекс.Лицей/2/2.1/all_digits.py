digits_set = set('0123456789')
num = input()
digits_set_in_num = set(num)
need_set = digits_set - digits_set_in_num
print(*need_set, sep=' ')
