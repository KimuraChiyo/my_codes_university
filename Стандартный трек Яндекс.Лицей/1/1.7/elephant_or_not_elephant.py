def whole_eleph(count_legs, count_tail, count_trunk,
                count_ears, count_eyes, count_mouth):
    trunk = count_trunk >= 1
    tail = count_tail >= 1
    mouth = count_mouth >= 1
    ears = count_ears // 2 >= 1
    eyes = count_eyes // 2 >= 1
    legs = count_legs // 4 >= 1
    whole_elephant = trunk and tail and legs and ears and eyes and mouth
    return whole_elephant


count_legs = 0
count_tail = 0
count_trunk = 0
count_ears = 0
count_eyes = 0
count_mouth = 0

count, body_part = int(input()), input()
while body_part != 'ОБЕД':
    if whole_eleph(count_legs, count_tail, count_trunk,
                   count_ears, count_eyes, count_mouth):
        break
    if body_part == 'хобот':
        count_trunk += count
    elif body_part == 'хвост':
        count_tail += count
    elif body_part == 'нога':
        count_legs += count
    elif body_part == 'ухо':
        count_ears += count
    elif body_part == 'глаз':
        count_eyes += count
    elif body_part == 'рот':
        count_mouth += count

    count, body_part = int(input()), input()

whole_elephant = whole_eleph(count_legs, count_tail, count_trunk,
                             count_ears, count_eyes, count_mouth)
if whole_elephant:
    print('Есть слон!')

    count = 0
    while whole_elephant:
        count += 1
        count_trunk -= 1
        count_tail -= 1
        count_legs -= 4
        count_ears -= 2
        count_eyes -= 2
        count_mouth -= 1
        whole_elephant = whole_eleph(count_legs, count_tail, count_trunk,
                                     count_ears, count_eyes, count_mouth)
    print(count)

else:
    print('Какие-то слоны нецелые. Пошли обедать.')
