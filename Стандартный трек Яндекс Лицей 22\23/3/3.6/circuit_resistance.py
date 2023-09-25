def circuit_resistance(*args, connection='serial', conductivity=False):
    R = 0
    if connection == 'serial':
        R = sum(args)
    else:
        args = [1 / Ri for Ri in args]
        R = 1 / sum(args)
    if conductivity:
        return 1 / R
    else:
        return R