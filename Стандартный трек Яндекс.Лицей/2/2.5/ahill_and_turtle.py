nums = []
num = int(input())
while num != 0:
    nums.append(num)
    num = int(input())

for i in range(len(nums) - 1):
    for j in range(len(nums) - i - 1):
        if nums[j] < nums[j + 1]:
            nums[j], nums[j + 1] = nums[j + 1], nums[j]
print(*nums, sep='->')