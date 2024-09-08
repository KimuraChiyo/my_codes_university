nums = list(map(int, input().split()))
dictionaries = []
for i in nums:
    dictionary = {}
    binary = str(bin(i))[2:]
    digits = len(binary)
    units = binary.count('1')
    zeros = binary.count('0')
    dictionary['digits'] = digits
    dictionary['units'] = units
    dictionary['zeros'] = zeros
    dictionaries.append(dictionary)
print(dictionaries)
    
    