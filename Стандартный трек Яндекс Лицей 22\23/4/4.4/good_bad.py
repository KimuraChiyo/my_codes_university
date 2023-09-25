import pymorphy2
import sys

morph = pymorphy2.MorphAnalyzer()


def agreement(phrase):
    phrase = phrase.split()
    noun = phrase[morph.parse(phrase[0])[0].tag.POS != 'NOUN']
    adjective = phrase[morph.parse(phrase[0])[0].tag.POS == 'NOUN']
    n = morph.parse(noun)[0]
    a = morph.parse(adjective)[0]
    tags = {n.tag.number, n.tag.case}
    if n.tag.number == 'sing':
        tags = tags.union({n.tag.gender})
    return a.inflect(tags).word + ' ' + noun


'''
a = [
    'добрая дракона',
    'злой волки',
    'котята милый',
    'весёлые собакой',
    'лес еловые',
    'глубокий обрывы',
    'глупые ухмылкам',
    'серенькое небом',
    'рыбы красивое'
]
'''
print(*[agreement(sentence) for sentence in sys.stdin], sep='\n')
