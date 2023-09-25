import pymorphy2
import sys

morph = pymorphy2.MorphAnalyzer()

for sentence in sys.stdin:
    lst = sentence.split()
    for k in lst:
        if morph.parse(k)[0].tag.POS == 'NOUN':
            word = morph.parse(morph.parse(k)[0].normal_form)[0]
        if k.isdigit():
            num = k
    print(num, word.make_agree_with_number(int(num)).word)
