from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits
from random import randint, choices


def name(lenght):
    len_first = randint(2, lenght - 2)

    count_of_digits = randint(1, len_first - 1)
    digits_first = choices(digits, k=count_of_digits)

    count_of_letters = len_first - count_of_digits
    letters_first = choices(ascii_letters, k=count_of_letters)

    for i in range(count_of_digits):
        position_of_digit = randint(1, len_first)
        letters_first.insert(position_of_digit, digits_first.pop())

    first_name = ''.join(map(str, letters_first))

    len_second = lenght - len_first - 1

    second_name = choices(ascii_uppercase[:len(ascii_uppercase) // 2], k=1) + choices(ascii_lowercase, k=len_second - 1)
    second_name = ''.join(map(str, second_name))

    full_name = first_name + ' ' + second_name
    return full_name
