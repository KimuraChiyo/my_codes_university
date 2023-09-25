prime_number = 2


def next_prime_number():
    global prime_number
    print(prime_number)
    prime_number += 1
    while len([i for i in range(1, prime_number + 1) if prime_number % i == 0]) != 2:
        prime_number += 1