sentences = []
sentence = input()
while sentence != '':
    sentences.append(sentence)
    sentence = input()
human_mention = '@' + input()
need_sentences = [i[i.index(' ') + 1:].capitalize() for i in sentences
                  if human_mention in i]
need_sentences.sort()
print(*need_sentences, sep='\n')
