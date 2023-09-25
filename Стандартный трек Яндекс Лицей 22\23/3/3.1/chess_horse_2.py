def horse2(field):
    curr_char, curr_num = field[0], field[1]
    chars = 'abcdefgh'
    nums = '12345678'
    for char in chars:
        dx = abs(chars.index(curr_char) - chars.index(char))
        if dx == 1 or dx == 2:
            for num in nums:
                dy = abs(nums.index(curr_num) - nums.index(num))
                if (dx == 2 and dy == 1) or (dx == 1 and dy == 2):
                    print(char, num, sep='')
# horse2('h1')
