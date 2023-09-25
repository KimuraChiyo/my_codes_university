word = input()
if len(word) % 2:
    end = len(word) // 2 + 1
else:
    end = len(word) // 2

step = len(word) // 2 + 1 if len(word) % 2 else len(word) // 2
for i in range(end):
    if i + step < len(word):
        print(word[i] + word[i + step], end='')
    else:
        print(word[i], end='')

    