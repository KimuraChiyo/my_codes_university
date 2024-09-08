# log = ['Иванов', 'Кузнецов', 'Петрова']
# blackboard = {'Иванов': False, 'Кузнецов': False, 'Петрова': False}
def pupil_number(surname):
    global log
    if surname in log:
        print(log.index(surname) + 1)
    else:
        print('Такого ученика нет.')


def add_pupil(surname):
    global log
    global blackboard
    if surname in log:
        print('Такой ученик уже есть в журнале.')
    else:
        print(f'Ученик {surname} добавлен.')
        log.append(surname)
        log.sort()
        blackboard[surname] = False


def to_the_blackboard(n):
    global log
    global blackboard
    person = log[n - 1]
    if not blackboard[person]:
        print(f'{person}, к доске!')
        blackboard[person] = True
    else:
        print('Сан Саныч, Вы меня уже вызывали!')


blackboard = {}
log = input()
log = log[log.index('[') + 1:log.rindex(']')].split()
for i in range(len(log)):
    if ',' in log[i]:
        log[i] = log[i][1:len(log[i]) - 2]
    else:
        log[i] = log[i][1:len(log[i]) - 1]
    blackboard[log[i]] = False