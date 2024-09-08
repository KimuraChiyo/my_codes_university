word = input()
count_sant = 0
count_kilo = 0
s = ''
for i in word:
    s += i
    if s == 'санти':
        s = ''
        count_sant += 1
    if s == 'кило':
        s = ''
        count_kilo += 1
count_of_zeros = count_kilo * 3 - count_sant * 2 + 2
zeros = abs(count_of_zeros) * '0'
if count_of_zeros > 0:
    print('1' + zeros)
elif count_of_zeros == 0:
    print('1')
else:
    print('1/1' + zeros)