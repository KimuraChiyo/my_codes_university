import sys
import pymorphy2
import string

morph = pymorphy2.MorphAnalyzer()

verbs = set()
for sentence in sys.stdin:
    for punct in string.punctuation:
        sentence = sentence.replace(punct, ' ')
    words = sentence.split()
    for word in words:
        parsed = morph.parse(word)
        for parsing in parsed:
            if 'VERB' in parsing.tag or 'INFN' in parsing.tag:
                verbs.add(parsing.normal_form)
                break
impf = []
perf = []
for word in verbs:
    parsed = morph.parse(word)
    for parsing in parsed:
        if 'INFN' in parsing.tag or 'VERB' in parsing.tag:
            tag = parsing.tag
            if 'impf' in tag:
                impf.append(parsing.word)
            elif 'perf' in tag:
                perf.append(parsing.word)
            break
print(*(sorted(impf) + sorted(perf)), sep='\n')
