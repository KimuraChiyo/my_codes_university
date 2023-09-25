separator = input()
words = input().upper().split()
print(' '.join([separator.join(i) for i in words]))

