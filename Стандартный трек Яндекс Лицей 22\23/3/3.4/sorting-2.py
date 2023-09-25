def sorting_bis(key, reverse):
    if key == 'abc':
        data.sort(reverse=reverse)
    else:
        data.sort(key=eval(key), reverse=reverse)