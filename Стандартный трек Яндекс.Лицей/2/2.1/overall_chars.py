set1 = set(input())
set2 = set(input())
set3 = set(input())
intersect12 = set1 & set2
intersect23 = set2 & set3
intersect13 = set1 & set3
need_set = intersect12 | intersect23 | intersect13
print(*need_set, sep='')