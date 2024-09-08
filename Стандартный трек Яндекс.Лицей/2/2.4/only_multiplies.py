nums = []
num = int(input())
while num != 0:
    nums.append(num)
    num = int(input())
corr_nums = []
for number in nums:
    if number % len(nums) == 0:
        corr_nums.append(number)
print(corr_nums)