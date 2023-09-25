def cheshir(first, last, *args):
    need_words = []
    for word in args:
        if first.lower() <= word.lower() <= last.lower():
            need_words.append(word)
    return need_words


first, *args, last = input().split()
print(*cheshir(first, last, *args))
