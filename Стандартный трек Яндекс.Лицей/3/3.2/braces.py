def brackets(line):
    flag = 0
    for i in line:
        if i == '(':
            flag += 1
        elif i == ')':
            flag -= 1
        if flag < 0:
            return False
    if flag == 0:
        return True
    else:
        return False

# line = "12 / (9 + 2(5(3 - 14))"
# print(brackets(line))