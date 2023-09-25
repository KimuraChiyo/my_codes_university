need_char = input()
count = 0
mx = -1
for i in range(int(input())):
    curr_symbol = input()
    if curr_symbol == need_char:
        count += 1
    else:
        if count > mx:
            mx = count
        count = 0
if count > mx:
    mx = count
print(mx)