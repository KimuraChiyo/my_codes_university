string = input() + ' '
words = []
non_alphas = []
word = ''
not_alpha = ''
for i in string:
    if i.isalpha():
        word += i
    elif i == ' ':
        if len(word) > 0:
            words.append(word.capitalize())
            word = ''
        if len(not_alpha) > 0:
            non_alphas.append(not_alpha)
            not_alpha = ''
    else:
        not_alpha += i
print(*words)
print(*non_alphas)