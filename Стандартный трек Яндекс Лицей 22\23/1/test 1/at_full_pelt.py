n = int(input())
word = input()
count_necessary = 0

for i in range(n):
    sentence = input()
    if 'забыл' in sentence or word in sentence:
        count_necessary += 1

if count_necessary <= n / 2:
    print('НЕ ТАК И МНОГО', n + count_necessary, sep='\n')
else:
    print('ВСЕ РАВНО НИЧЕГО СТРАШНОГО', n + count_necessary, sep='\n')