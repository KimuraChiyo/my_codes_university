memory = []


def prompter(substring):
    global memory
    for sentence in memory:
        if substring in sentence:
            return sentence
    memory.append(substring)
    return substring
