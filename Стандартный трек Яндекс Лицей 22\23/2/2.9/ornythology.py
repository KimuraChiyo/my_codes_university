dictionary = {}
string = input()
while string != '':
    name, count = string[:string.index(':')], int(string[string.rindex(' ') + 1:])
    dictionary[name] = dictionary.get(name, 0) + count
    string = input()
print(dictionary)
