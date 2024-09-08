first_word = input()
second_word = input()
flag = 0
if len(first_word) != len(second_word):
    print('NO')
else:
    special = 0
    for i in range(0, len(first_word)):
        special = i
        if (first_word[i:] + first_word[:i]) == second_word:
            flag = len(first_word) - i
            break
    if special != len(first_word) - 1:
        if flag == len(first_word):
            flag = 0
    else:
        flag = 'NO'
    print(flag)
