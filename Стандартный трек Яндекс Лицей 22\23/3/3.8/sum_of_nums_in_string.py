import sys

lst_of_nums = [[int(word) for word in row.split() if word[0] in '0123456789'] for row in sys.stdin]
condition_of_true = sum(max(lst_of_nums, key=lambda x: (len(x), -sum(x)))) if not all(
    [len(x) == 0 for x in lst_of_nums]) else -1
print(condition_of_true)
