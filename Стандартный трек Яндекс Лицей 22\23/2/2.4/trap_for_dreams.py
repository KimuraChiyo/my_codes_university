dreams = []
dream = input()
while dream != '':
    dreams.append(dream)
    dream = input()
start = int(input()) - 1
end = int(input())
lenght = len(max(dreams[start:end], key=len))
for dream in dreams:
    if len(dream) == lenght:
        print(dream)
        break