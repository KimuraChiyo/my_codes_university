def accumulation(*args):
    lst = []
    accumul = 0
    lst.append(accumul)
    for i in args:
        accumul += i
        lst.append(accumul)
    return lst
