count_of_words = int(input())
for index_word in range(count_of_words):
    word = input()
    for index_char in range(1, len(word)):
        if word[index_char - 1] > word[index_char]:
            print((index_word, index_char))