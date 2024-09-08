count_of_classes = int(input())
parallels = [0 for i in range(11)]
count_of_classes_in_parallel = [count_of_classes for i in range(11)]
for i in range(count_of_classes * 11):
    count = int(input())
    if count == 0:
        count_of_classes_in_parallel[i % 11] -= 1
    parallels[i % 11] += count

count_of_classes_in_parallel = [(i if i != 0 else 1) 
                                for i in count_of_classes_in_parallel]
parallels = [parallels[i] / count_of_classes_in_parallel[i]
             for i in range(len(parallels))]
mx = parallels.index(max(parallels))
mn = parallels.index(min([i for i in parallels if i != 0]))
print(mn + 1, mx + 1)

