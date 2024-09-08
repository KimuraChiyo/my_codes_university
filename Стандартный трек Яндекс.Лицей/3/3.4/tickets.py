def allocation(data):
    fake = []
    for arr, ind in data:
        if places[arr - 1][ind - 1]:
            fake.append((arr, ind))
        else:
            places[arr - 1][ind - 1] = 1
    return fake