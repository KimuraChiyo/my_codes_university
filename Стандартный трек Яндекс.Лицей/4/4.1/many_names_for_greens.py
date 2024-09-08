import string
import random


def name(lenght):
    letters = list(string.ascii_uppercase) + list(string.ascii_lowercase) + list(string.digits)
    used = []

    lenght_first = random.randint(2, lenght - 2)
    lenght_second = lenght - lenght_first - 1

    first_name = []

    first_letter_first = letters[:-10][random.randint(0, len(letters[:-10]) - 1)]
    first_name.append(first_letter_first)
    used.extend([first_letter_first, first_letter_first.swapcase()])

    for i in range(lenght_first - 2):
        letter = letters[random.randint(0, len(letters) - 1)]
        while letter in used:
            letter = letters[random.randint(0, len(letters) - 1)]
        used.extend([letter, letter.swapcase()] if not letter.isnumeric() else [letter])
        first_name.append(letter)

    digit_first = letters[-10:][random.randint(0, 9)]
    while digit_first in used:
        digit_first = letters[-10:][random.randint(0, 9)]
    used.append(digit_first)
    first_name.append(digit_first)

    first_name = ''.join(first_name)

    second_name = []

    first_letter_second = letters[:13][random.randint(0, 12)].upper()
    while first_letter_second in used:
        first_letter_second = letters[:13][random.randint(0, 12)].upper()
    used.extend([first_letter_second, first_letter_second.swapcase()])
    second_name.append(first_letter_second)

    for i in range(lenght_second - 1):
        letter = letters[26: 26 + 26][random.randint(0, 25)]
        while letter in used:
            letter = letters[26: 26 + 26][random.randint(0, 25)]
        used.extend([letter, letter.swapcase()])
        second_name.append(letter)

    second_name = ''.join(second_name)

    full_name = first_name + ' ' + second_name
    return full_name


def little_green_men_names(m, n):
    set_names = set()
    while len(set_names) != m:
        set_names.add(name(n))
    return set_names
