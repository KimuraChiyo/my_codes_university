word = input()
step = int(input())
right = -step
left = step
for i in range(len(word) // step):
    if len(word) >= step:
        if not i % 2:
            print(word[right:])
            word = word[:right]
        else:
            print(word[:left])
            word = word[left:]
if len(word) > 0:
    print(word)
