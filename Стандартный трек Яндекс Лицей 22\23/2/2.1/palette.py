count_seq = int(input())
set_colors = set()
exclusive_numbers = set()
count = 0
for i in range(count_seq):
    num_of_colors = int(input())
    for i in range(num_of_colors):
        color = input()
        if color in set_colors:
            if color in exclusive_numbers:
                count += 1
            else:
                exclusive_numbers.add(color)
                count += 1
        else:
            set_colors.add(color)
print(len(exclusive_numbers), len(exclusive_numbers) + count)