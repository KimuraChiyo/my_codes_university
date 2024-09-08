average = 0


def changing_the_norm(data):
    global average
    count = 0
    for value in data:
        if value > average:
            count += 1
    average = sum(data) / len(data)
    return count