word = input()
ln = len(word)

if ln % 2:
    right = ln // 2
    left = ln // 2
    end = ln // 2 + 1
    space_between = 1
    space_before = ln // 2
else:
    right = ln // 2 - 1
    left = ln // 2
    end = ln // 2
    space_between = 0
    space_before = ln // 2 - 1

for i in range(end):
    if right != left:
        print(space_before * ' ' + word[right] + space_between * ' ' + word[left])
    else:
        print(space_before * ' ' + word[right])
    right -= 1
    left += 1
    if i != 0 or not ln % 2:
        space_between += 2
    space_before -= 1