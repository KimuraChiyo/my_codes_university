words = []
word = input()
while word != '':
    words.append(word)
    word = input()

words_len = words[:]
for i in range(len(words) - 1):
    for j in range(len(words) - i - 1):
        if len(words_len[j]) > len(words_len[j + 1]):
            words_len[j], words_len[j + 1] = words_len[j + 1], words_len[j]

words_alphabetic = words[:]
for i in range(len(words) - 1):
    for j in range(len(words) - i - 1):
        if words_alphabetic[j] > words_alphabetic[j + 1]:
            words_alphabetic[j], words_alphabetic[j + 1] = (
                words_alphabetic[j + 1], words_alphabetic[j])

flag = 'YES'
for index in range(len(words)):
    if words_alphabetic[index] != words_len[index]:
        flag = words_alphabetic[index] + ' ' + words_len[index]
        break
print(flag)