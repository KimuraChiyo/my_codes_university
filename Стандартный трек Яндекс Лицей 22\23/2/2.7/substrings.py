string = input()
set_of_substrings = set()
for i in range(len(string) // 2):
    for k in range(len(string) - i):
        set_of_substrings.add(string[k:k + i])
for i in sorted(sorted(list(set_of_substrings)), key=len):
    if string.count(i) >= 2 and i != '':
        print(f'{i}: {string.count(i) }')