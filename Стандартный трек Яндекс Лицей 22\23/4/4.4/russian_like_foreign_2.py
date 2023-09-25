import pymorphy2
import sys

morph = pymorphy2.MorphAnalyzer()


def participle(word, **grammems):
    word = morph.parse(word)[0]
    grammems = set(grammems.values())
    return word.inflect(grammems).word