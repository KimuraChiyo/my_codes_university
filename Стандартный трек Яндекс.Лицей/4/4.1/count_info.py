from math import log2

a = input()
print(log2(len(set(a))) * len(a))
