first = input().split()
second = input().split('_|_')
third = input().split('_0_')
for word in first:
    print(word + ':')

    need_in_second = [i.capitalize() for i in second if len(set(i.lower())) != len(i.lower()) and len(i) <= len(word)]
    print('* '.join(need_in_second))

    need_in_third = [i.upper() for i in third if i.lower() > word.lower() and i.islower()]
    joiner = '*' + word[-2].upper() + '*'
    print(joiner.join(need_in_third))
    