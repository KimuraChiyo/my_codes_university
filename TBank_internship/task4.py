def divisors(num):
    d = set()
    for i in range(1, int(num**0.5)+1, (num % 2)+1):
        if (num % i == 0):
            d |= {i, num//i}
    return d

def isPrime(num):
    return num > 1 and len(divisors(num)) == 2

a, b = list(map(int, input().split()))
print(sum([(not isPrime(num) and isPrime(len(divisors(num)))) for num in range(a, b + 1)]))


# 2
'''
1 9
'''

# 1
'''
1 9
'''

# 1
'''
6 9
'''