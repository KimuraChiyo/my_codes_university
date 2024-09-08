word = 'ABCDEFGHIJKLMNOPQRSTUVWXYZABC'
index = int(input()) - 1
for i in range(index, index + 4):
    print(word[i], end='')
