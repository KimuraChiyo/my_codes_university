string = input()
luminous = int(input())
if luminous > 100:
    string = string.replace('0000', '|||')
else:
    string = string.replace('|||', '00', 3)
if '|0|' in string:
    string = string.replace('|0|', '|00|', 1)
print(string)

