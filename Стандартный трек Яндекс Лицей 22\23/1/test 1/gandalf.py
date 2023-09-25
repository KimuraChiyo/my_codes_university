string = input()
count = 0
while 'Гэндальф' not in string:
    if 'волшебн' in string:
        count += len(string)
    string = input()

print(count)