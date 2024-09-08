count_of_flags = int(input())
flags = [input() for i in range(count_of_flags)]
len_of_garland = int(input())
garland = [flags[i % count_of_flags] for i in range(len_of_garland)]
print(*garland, sep='\n')