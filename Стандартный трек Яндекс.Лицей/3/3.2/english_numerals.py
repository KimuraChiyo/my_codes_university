def numerals(num):
    s = ''
    if num // 10 == 0:
        s += ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'][num % 10]
    elif num // 10 == 1:
        index = num % 10
        nums = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen',
                'nineteen']
        s = nums[index]
    elif num // 10 >= 2:
        s += ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety'][num // 10]
        s += ['', '-one', '-two', '-three', '-four', '-five', '-six', '-seven', '-eight', '-nine'][num % 10]
    return s

# for i in range(0, 100):
#     print(numerals(i))