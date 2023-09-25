count_descriptions = int(input())
reformat_strings = set()
for i in range(count_descriptions):
    string = input()
    m = int(input())
    k = int(input())
    reformat_string = string[:m:k]
    reformat_strings.add(reformat_string)
print(*reformat_strings, sep='\n')
