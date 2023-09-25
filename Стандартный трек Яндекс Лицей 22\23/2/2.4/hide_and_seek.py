count_sentence = int(input())
sentences = list()
for i in range(count_sentence):
    sentences.append(input())

count_names = int(input())
for i in range(count_names):
    index = -1
    name = input()
    for index_sentence in range(len(sentences)):
        if name in sentences[index_sentence]:
            index = index_sentence + 1
            break
    print(index)

