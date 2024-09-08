import sys

lst_of_metals = [i.split() for i in sys.stdin]
metals = list(map(lambda x: (x[0], float(x[-2]), x[-1]), lst_of_metals))
metals = [(x[0], (x[1] + 273.15 if x[2] == 'C' else x[1]), ('K' if x[2] != 'K' else 'K')) for x in metals]
curr_temp_k = metals[-1][1]
metals = metals[:-1]
print(*set([x[0] for x in metals if x[1] < curr_temp_k]), sep='\n')
