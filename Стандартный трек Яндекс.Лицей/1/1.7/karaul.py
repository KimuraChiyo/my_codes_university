n = int(input())
while n != 0:
    del_three = (n % 3 == 0)
    del_seven = (n % 7 == 0)
    if del_three and del_seven:
        print('Караул!')
        break
    elif del_three:
        print('несчастливое')
    elif del_seven:
        print('опасное')
    else:
        print(n)
    n = int(input())