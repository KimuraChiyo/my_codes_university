sentences = []
count_of_sentences = int(input())
for i in range(count_of_sentences):
    sentence = input()
    text = sentence[:len(sentence) - 2]
    num = int(sentence[-1])
    sentences.append((text, num))

for i in range(len(sentences) - 1):
    if sentences[i][1] < sentences[i + 1][1]:
        print((i + 1, sentences[i][0]))

