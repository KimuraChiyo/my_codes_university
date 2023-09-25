import sys

condition_of_fail = all([any([num for num in map(int, row.strip().split('; ')) if num % 5 == 0]) for row in sys.stdin])
print('FAIL' if condition_of_fail else 'OK')
