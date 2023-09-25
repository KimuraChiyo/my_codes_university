count_of_arrays = int(input())
ridges = [[] for i in range(count_of_arrays)]
count_of_words = int(input())
words = []
for _ in range(count_of_words):
    plant = input()
    words.append(plant)
words = sorted(sorted(words), key=len)

arr = 0
while len(words) > 0:
    ridges[arr].append(words.pop(0))
    arr += 1
    if arr == count_of_arrays:
        arr = 0

[print(', '.join(row)) for row in ridges]