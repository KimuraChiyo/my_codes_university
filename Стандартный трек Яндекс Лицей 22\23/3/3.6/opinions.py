def opinions(*args):
    dct = {}
    for dct_inner in args:
        for key, value in dct_inner.items():
            if key in dct.keys():
                dct[key].add(value)
            else:
                dct[key] = set()
                dct[key].add(value)
    return dct