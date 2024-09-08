n = int(input())
first = input()
second = input()
if first > second:
    first, second = second, first
    
if len(first) < n and len(second) < n:
    print(first, second, sep='\n')
elif len(first) < n and len(second) >= n:
    print(first)
elif len(first) >= n and len(second) < n:
    print(second)
else:
    print(n)