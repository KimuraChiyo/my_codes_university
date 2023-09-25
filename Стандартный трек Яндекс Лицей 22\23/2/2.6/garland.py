sentence = input()
mx_len = len(max(sentence.split(), key=len))
words = [i.ljust(mx_len, ' ') for i in sentence.split()]
for i in range(mx_len):
    for k in range(len(words)):
        if i == 0:
            print('_' + words[k][i], end='')
        else:
            print(' ' + words[k][i], end='')
    if i == 0:
        print('_')
    else:
        print()
print()
for i in range(mx_len - 1, -1, -1):
    for k in range(len(words)):
        if i == 0:
            print('_' + words[k][i], end='')
        else:
            print(' ' + words[k][i], end='')
    if i == 0:
        print('_')
    else:
        print()