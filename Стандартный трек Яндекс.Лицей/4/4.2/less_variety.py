from PIL import Image


def less_variety(in_filename, out_filename):
    image = Image.open(in_filename)
    width, height = image.size

    colors = set()
    pixels = image.load()
    for i in range(width):
        for j in range(height):
            colors.add(pixels[i, j])
    count_colors = len(colors)
    while count_colors >= 256:
        count_colors //= 2

    image = image.resize((width // 2, height // 2))
    image = image.quantize(count_colors)
    image.save(out_filename)
