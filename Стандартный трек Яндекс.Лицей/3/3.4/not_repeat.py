def number_of_divisors(num):
    if num in divisors:
        return divisors[num]
    divs = set()
    for i in range(1, int(num ** 0.5) + 1):
        if num % i == 0:
            divs.add(i)
            divs.add(num // i)
    divisors[num] = len(divs)
    return len(divs)


divisors = {}