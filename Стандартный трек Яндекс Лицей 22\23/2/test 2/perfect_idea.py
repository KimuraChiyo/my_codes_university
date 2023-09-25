count = 0
string = input()
while not string.isupper() and not string.startswith('отпечаток'):
    actions = [string.upper(),
               ' '.join([i.capitalize() for i in string.split()]),
               string.lower(),
               string.capitalize()]
    print(actions[count % 4])
    count += 1
    string = input()
