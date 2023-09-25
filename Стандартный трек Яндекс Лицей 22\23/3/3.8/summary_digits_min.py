import sys

print(min(sorted(list(map(int, sys.stdin))), key=lambda x: (sum(map(int, str(x).strip())), -len(str(x)))))
