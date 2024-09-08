dictionary = {}


def diversity(string):
    global dictionary
    dictionary[string] = dictionary.get(string, 0) + 1
    return dictionary[string]