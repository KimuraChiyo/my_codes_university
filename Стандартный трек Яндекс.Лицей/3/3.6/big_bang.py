from math import prod


def future(*mass, **const):
    curr_VIN = sum(mass) * prod(const.values())
    if curr_VIN > VIN:
        flag = 'ACCELERATION'
    elif curr_VIN < VIN:
        flag = 'DECELERATION'
    else:
        flag = 'UNCHANGED'
    return flag
