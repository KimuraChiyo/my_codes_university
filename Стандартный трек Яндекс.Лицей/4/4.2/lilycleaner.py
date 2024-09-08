from PIL import Image


def search_for_lilies(image, color):
    x, y = image.size
    pixels = image.load()

    pixels_cols = []
    for k in range(x):
        count = 0
        for j in range(y):
            if pixels[k, j] == color:
                count += 1
        pixels_cols.append(count)
    X = pixels_cols.index(max(pixels_cols))
    return X * 1001 // y - 500
