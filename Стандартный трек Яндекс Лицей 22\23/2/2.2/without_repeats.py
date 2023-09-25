word = input()
while word != '':
    if len(set(word)) == len(word):
        print(word)
    word = input()