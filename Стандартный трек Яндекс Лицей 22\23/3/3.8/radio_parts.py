n = int(input())
lst = [input().split(', ') for i in range(n)]
lst = sorted(lst, key=lambda x: (-int(x[1]), x[0], float(x[2])))
print(*[f'{pos[0]}: {pos[2]}; {pos[1]}' for pos in lst], sep='\n')
