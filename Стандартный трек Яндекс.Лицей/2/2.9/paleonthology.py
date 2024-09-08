dictionary = {'Archaea': range(4500 * 10 ** 6, 2800 * 10 ** 6, -1),
              'Proterozoic': range(2800 * 10 ** 6, 635 * 10 ** 6, -1),
              'Paleozoic': range(635 * 10 ** 6, 300 * 10 ** 6, -1),
              'Mesozoic': range(300 * 10 ** 6, 145 * 10 ** 6, -1),
              'Cenozoic': range(145 * 10 ** 6, 0, -1)}
age = input()
while age != '':
    age = int(age) * 1000
    for name, ages in dictionary.items():
        if age in ages:
            print(name)
    age = input()
