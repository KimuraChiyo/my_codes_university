num_of_multiped = int(input())
set_over_40 = set()
set_even = set()
set_3 = set()
for i in range(num_of_multiped):
    count_of_legs = int(input())
    if count_of_legs > 40:
        set_over_40.add(count_of_legs)
    if not count_of_legs % 2:
        set_even.add(count_of_legs)
    if count_of_legs % 3 == 0:
        set_3.add(count_of_legs)

intersect_all = set_over_40 & set_even & set_3
even_40 = set_over_40 & set_even - intersect_all
even_3 = set_3 & set_even - intersect_all
nums_3_40 = set_over_40 & set_3 - intersect_all
need_set = even_40 | even_3 | nums_3_40
print(*need_set, sep=' ')