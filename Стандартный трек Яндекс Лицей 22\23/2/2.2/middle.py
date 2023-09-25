from math import ceil
word = input()
word = word[:ceil(len(word) / 2)]
print(word[-1])
