sentences = []
sentence = input()
while sentence != 'разбитое корыто':
    sentences.append(sentence)
    sentence = input()

for i in range(len(sentences) - 1):
    for j in range(len(sentences) - i - 1):
        if len(sentences[j]) > len(sentences[j + 1]):
            sentences[j], sentences[j + 1] = sentences[j + 1], sentences[j]
print(*sentences, sep='\n')