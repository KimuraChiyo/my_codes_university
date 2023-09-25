inputs = []
word = input()
while word != '':
    inputs.append(word)
    word = input()

lenght_of_block = len(max(inputs, key=len))

for word in inputs[::-1]:
    if not (lenght_of_block - len(word)) % 2:
        left = (lenght_of_block - len(word)) // 2
        right = (lenght_of_block - len(word)) // 2
    else:
        left = (lenght_of_block - len(word)) // 2
        right = (lenght_of_block - len(word)) // 2 + 1
    print('-' * left + word + '-' * right)
