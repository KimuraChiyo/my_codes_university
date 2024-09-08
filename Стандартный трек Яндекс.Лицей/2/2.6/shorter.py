string = input()
print(*[string[i:len(string) - i] for i in range(len(string) // 2 + 1)
        if len(string[i:len(string) - i]) > 0], sep='\n')