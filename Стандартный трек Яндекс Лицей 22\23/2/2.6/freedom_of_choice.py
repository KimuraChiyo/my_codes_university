splitter, lenght, string = input().split()
lenght = int(lenght)
print(splitter[::-1].join([i for i in string.split(splitter) 
                           if len(set(i)) >= lenght]))
