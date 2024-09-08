sentence = input() + ' '
correct_sentence = ''
count = 0
for i in sentence:
    if i == '[':
        count += 1
    elif i == ']':
        count -= 1
    if count == 0 and i != ']':
        correct_sentence += i
    else:
        continue
print(correct_sentence)