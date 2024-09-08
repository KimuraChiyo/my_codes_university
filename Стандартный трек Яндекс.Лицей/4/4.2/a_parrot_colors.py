from PIL import Image


def direction(image, color):
    x, y = image.size
    x_mid, y_mid = x // 2, y // 2
    pixels = image.load()

    ks, js = 0, 0
    count = 0
    for k in range(x):
        for j in range(y):
            if pixels[k, j] == color:
                ks += k
                js += j
                count += 1
    ks //= count
    js //= count
    return [abs(ks - x_mid), abs(js - y_mid)]
