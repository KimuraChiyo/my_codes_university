string = input() + ' '
word = ''
count_overall = 0
for i in string:
    if i != ' ':
        word += i
    elif (i == ' ' and len(word) > 0):
        count = 0
        for i in word:
            if i in 'аяоёэеуюыи':
                count += 1
        if count > 0:
            count_overall += count - 1
        word = ''
print(count_overall)