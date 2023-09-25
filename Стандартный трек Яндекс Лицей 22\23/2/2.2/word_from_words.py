flag = False
count_words = int(input())
final_word = ''
for i in range(1, count_words + 1):
    word = input()
    if i > len(word):
        flag = True
        continue
    else:
        final_word += word[-i]
if flag:
    print(None)
else:
    print(final_word)