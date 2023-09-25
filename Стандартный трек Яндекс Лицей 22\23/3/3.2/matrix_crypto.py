from math import ceil


def encrypt(text, n):
    lenght = ceil(len(text) / n) * n
    text = text.ljust(lenght, ' ')
    s = ''
    for i in range(n):
        s += text[i::n]
    return s


def decrypt(text, n):
    step = len(text) // n
    s = ''
    for i in range(step):
        s += text[i::step]
    return s

# print(encrypt('Whirling, twirling round and round Falling softly to the ground.', 8))
# print(decrypt('W,n nny h gadg git n  trrwrdFsoolio ao uirurlftnnlnolthdgiduile.', 8))