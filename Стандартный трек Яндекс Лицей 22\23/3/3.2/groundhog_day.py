def groundhog_day(data):
    for index_data in range(1, len(data)):
        indexes = []
        prev = data[index_data - 1]
        curr = data[index_data]
        for ind_char in range(len(prev)):
            if prev[ind_char] != curr[ind_char]:
                indexes.append(ind_char)
        if len(indexes) > 2:
            return index_data, *indexes
    return 0, 0

# data = ["I Got You, Babe", "I Got You, aabe", "I GoS YoU,Raabe"]
# print(groundhog_day(data))