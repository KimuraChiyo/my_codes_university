word = input()
index = 0
for i in range(len(word)):
    if word[i] == '-':
        index = i
        break
        
print(word[index + 1:] + '-' + word[:index])

