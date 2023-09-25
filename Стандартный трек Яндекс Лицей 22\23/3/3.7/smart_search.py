def smart_search(*args, func=lambda x: x):
    if type(args[0]) == str:
        return tuple([i for i in args if i[0].isupper()])
    return tuple(filter(func, args))
