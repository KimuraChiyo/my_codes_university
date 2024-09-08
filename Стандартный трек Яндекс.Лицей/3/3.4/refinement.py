def refinement(array):
    list.extend(array)
    data = [i for i in list if i % 2 == sum(list) % 2]
    return sum(data) / len(data) if len(data) != 0 else 0


list = []