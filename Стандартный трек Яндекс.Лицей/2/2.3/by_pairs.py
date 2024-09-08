word = input()
for i in range(0, len(word), 2):
    print(word[i:i + 2], end='\n')