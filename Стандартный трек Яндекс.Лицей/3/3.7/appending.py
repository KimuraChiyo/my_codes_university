inputs = input().split()
print(*list(map(lambda x: x.rjust(len(max(inputs, key=len)), '*'), inputs)), sep='\n')
