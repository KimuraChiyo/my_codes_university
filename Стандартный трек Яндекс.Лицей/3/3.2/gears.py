def gears(arr, n, m):
    gears = []
    for box in arr:
        gears.extend(box)
    gears.sort()
    for ind in range(len(gears)):
        curr_gear = gears[ind]
        another_gears = gears[:ind] + gears[ind + 1:]
        for gear in another_gears:
            if gear != 0:
                if curr_gear / gear == n / m:
                    return curr_gear, gear
    return None, None

# data = [[0, 30], [3, 21], [16]]
# print(gears(data, 30, 15))
