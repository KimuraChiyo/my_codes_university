used_digits = set()
count_of_nums = int(input())
for i in range(count_of_nums):
    num = input()
    for digit in num:
        used_digits.add(digit)
print(len(used_digits))
