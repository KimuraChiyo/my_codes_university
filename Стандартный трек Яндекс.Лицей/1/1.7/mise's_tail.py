block_size = int(input())
count_words = int(input())
indent = 0
return_indent = 0
ret_flag = 0
for i in range(count_words):
    word = input()
    if ret_flag:
        print(' ' * (block_size - return_indent - len(word)) + word)
        if block_size - return_indent - len(word) <= 0:
            ret_flag = 0
            indent = 1
            return_indent = 0
        else:
            return_indent += 1
    else:
        if indent + len(word) <= block_size:
            print(' ' * indent + word)
            indent += 1
        else:
            print(' ' * (block_size - len(word)) + word)
        if indent + len(word) - block_size >= 1:
            return_indent += 1
            ret_flag = 1
