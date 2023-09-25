count_sentence = int(input())
sentences = list()
for i in range(count_sentence):
    sentences.append(input())

count_names = int(input())
names = list()
for i in range(count_names):
    names.append(input())

for sentence in sentences:
    flag = True
    for name in names:
        if name not in sentence:
            flag = False
            break
    if flag:
        print(sentence)

