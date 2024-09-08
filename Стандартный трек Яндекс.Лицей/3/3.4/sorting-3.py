def sorting_triple(key, reverse):
    data.sort(key=lambda x: len(str(x)) if key == 'len' else x, reverse=reverse)