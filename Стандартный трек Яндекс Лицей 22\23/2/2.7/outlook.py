sentence = input()
heights = [int(i) for i in sentence.split()]
curr_max = heights[0]
outlook = []
for i in heights:
    if i > curr_max:
        curr_max = i
        outlook.append(str(i))
outlook.insert(0, str(heights[0]))
print('>>'.join(outlook), sep='')