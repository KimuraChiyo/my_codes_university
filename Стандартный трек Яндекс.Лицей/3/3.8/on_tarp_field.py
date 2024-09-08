import sys

condition_of_true = all([len([num for num in row.strip().split() if '0' in num]) <= len(
    [num for num in row.strip().split() if '0' not in num]) for row in sys.stdin])
print('evergreen tomatoes'.upper() if condition_of_true else 'aluminum cucumbers'.upper())
