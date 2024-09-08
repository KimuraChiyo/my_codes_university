import pymorphy2

morph = pymorphy2.MorphAnalyzer()


def russian_noun(in_word, case='nomn', number='sing'):
    word = morph.parse(in_word)[0]
    return word.inflect({case, number}).word
