import itertools
matrix = [
    [530, 301, 432, 402, 533, 621, 120],
    [534, 219, 673, 551, 344, 762, 324],
    [356, 776, 443, 622, 632, 511, 209],
    [177, 446, 840, 332, 542, 631, 761],
    [432, 112, 532, 762, 544, 226, 331],
    [633, 422, 773, 533, 721, 652, 560],
    [438, 232, 345, 761, 354, 231, 362]]

mn_cost = 5000
mn_route = ''

for route in itertools.permutations(list(range(7))):
    cost = 0
    for i in range(len(route) - 1):
        cost += matrix[route[i]][route[i + 1]]
    cost += matrix[route[-1]][route[0]]
    if cost < mn_cost:
        mn_cost = cost
        mn_route = ''.join([str(i + 1) for i in route])

print(mn_cost, mn_route)
