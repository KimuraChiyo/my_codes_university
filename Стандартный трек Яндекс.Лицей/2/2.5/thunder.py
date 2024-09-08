count_of_places = int(input())
nums = [(int(input()), float(input())) for i in range(count_of_places)]
for i in range(len(nums) - 1):
    for j in range(len(nums) - i - 1):
        if nums[j][1] < nums[j + 1][1]:
            nums[j], nums[j + 1] = nums[j + 1], nums[j]
for i in range(len(nums) - 1):
    for j in range(len(nums) - i - 1):
        if nums[j][0] < nums[j + 1][0]:
            nums[j], nums[j + 1] = nums[j + 1], nums[j]
print(*nums, sep='\n')