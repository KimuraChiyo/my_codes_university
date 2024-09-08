sentence = input() + ' '
word = ''
for i in sentence:
    if i != ' ':
        word += i
    else:
        print(word)
        word = ''