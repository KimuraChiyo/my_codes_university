from PIL import Image


def wb_negative(filename):
    image = Image.open(filename)
    pixels = image.load()
    x, y = image.size

    for i in range(x):
        for j in range(y):
            r, g, b = pixels[i, j]
            bw = (r + g + b) // 3
            pixels[i, j] = 255 - bw, 255 - bw, 255 - bw

    image.save("out.png")
