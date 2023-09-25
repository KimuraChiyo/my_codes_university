count_seq = int(input())
for i in range(count_seq):
    first = [int(i) for i in input().split() if len(i) == 2]
    second = [int(i) for i in input().split() if len(i) == 2]
    in_all = sorted(set(first) & set(second), reverse=True)
    print(': '.join(list(map(str, in_all))))