def complex_systems(arr):
    itog_arr = []
    for elem in arr:
        if type(elem) == list:
            app_arr = complex_systems(elem)
            itog_arr.extend(app_arr)
        else:
            itog_arr.append(elem)
    return itog_arr
