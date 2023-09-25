import pymorphy2
import sys
import string

morph = pymorphy2.MorphAnalyzer()
names = set()
animacy = set()
for i in sys.stdin:
    sentence = i
    for k in string.punctuation:
        sentence = sentence.replace(k, ' ')
    words = sentence.split()
    for word in words:
        if 'Name' in morph.parse(word)[0].tag:
            names.add(morph.parse(word)[0].normal_form.capitalize())
        elif 'anim' in morph.parse(morph.parse(word)[0].normal_form)[0].tag:
            animacy.add(morph.parse(word)[0].normal_form)
print(*sorted(names))
print(*sorted(animacy, key=lambda x: (len(x), x), reverse=True))
