import sys

print(max(sys.stdin, key=lambda x: (x.count('a'), len(x), max(x[0]))))
