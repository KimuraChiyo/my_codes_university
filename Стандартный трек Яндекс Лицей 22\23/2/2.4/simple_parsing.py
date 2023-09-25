need = []
string = input()
s = ''
while string != '</html>':
    if string.startswith('<p>'):
        while not string.endswith('</p>'):
            s += string + ' '
            string = input()
        else:
            s += string + ' '
        need.append(s[3:len(s) - 5])
        s = ''
    string = input()
print(*need[::-1], sep='\n')