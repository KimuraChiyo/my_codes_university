sentence = input()
english = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
russian = 'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя'
chars = set([i for i in list(sentence) if i in english or i in russian])
for char in chars:
    if char in english:
        index = 1
        for symbol in english:
            if symbol != char:
                index += 1
            else:
                print((char, index))
                break
    else:
        index = 1
        for symbol in russian:
            if symbol != char:
                index += 1
            else:
                print((char, index))
                break
