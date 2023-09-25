count_of_words = int(input())
words = ([''] + [input() for i in range(count_of_words)] +
         ['яяяяяяяяяяяяяяяяяяяяяяяяяяяяя'])
word = input()
for i in range(len(words) - 1):
    # print(words[i], words[i] <= word < words[i + 1], words[i + 1])
    if words[i] <= word < words[i + 1]:
        print(i)
