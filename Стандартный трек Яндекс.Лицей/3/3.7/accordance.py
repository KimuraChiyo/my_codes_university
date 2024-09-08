def trend(*data, **functions):
    data_x = [i[0] for i in data]
    data_y = [i[1] for i in data]
    for func_name in functions.keys():
        func = functions[func_name]
        func_y = [func(i) for i in data_x]
        if all([abs(func_y[i] - data_y[i]) <= 0.01 for i in range(len(data_x))]):
            return func_name
