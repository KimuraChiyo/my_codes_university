def brackets(line):
    string = ''
    for i in line:
        if i in '<>()[]{}':
            string += i
    while '{}' in string or '[]' in string or '()' in string or '<>' in string:
        string = string.replace('{}', '')
        string = string.replace('()', '')
        string = string.replace('[]', '')
        string = string.replace('<>', '')
    if len(string) > 0:
        return False
    else:
        return True

# line = "1{2 + [3}45 - 6] * (7 - 8) 9"
# print(brackets(line))