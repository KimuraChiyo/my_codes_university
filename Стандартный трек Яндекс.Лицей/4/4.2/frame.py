from PIL import Image, ImageOps


def frame(filename, width):
    image = Image.open(filename)
    x, y = image.size
    image = image.crop((x // 3, y // 3, x // 3 * 2, y // 3 * 2))

    x, y = image.size
    pixels = image.load()
    red, green, blue = [], [], []
    for i in range(x):
        for j in range(y):
            r, g, b = pixels[i, j]
            red.append(r)
            green.append(g)
            blue.append(b)
    r_frame = sum(red) // len(red)
    g_frame = sum(green) // len(green)
    b_frame = sum(blue) // len(blue)
    pixel_frame = (r_frame, g_frame, b_frame)
    image = ImageOps.expand(image, border=width, fill=pixel_frame)
    image.save('done.png')
