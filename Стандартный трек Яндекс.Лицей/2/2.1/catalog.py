knowledge = set()
count_of_names = int(input())
for i in range(count_of_names):
    name = input()
    if name in knowledge:
        print('ДА')
    else:
        print('НЕТ')
        knowledge.add(name)
