main_container = set()
num = input()
wrong_nums = set()
while num != '':
    curr_container = set()
    num = int(num)

    while num != -1:
        curr_container.add(num)
        num = int(input())

    for number in curr_container:
        
        if number in main_container:
            main_container.remove(number)
            wrong_nums.add(number)
            
        elif number not in main_container and number not in wrong_nums:
            main_container.add(number)
            
    num = input()
print(*main_container, sep=' ')
