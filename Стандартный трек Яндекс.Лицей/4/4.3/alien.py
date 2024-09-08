from PIL import Image, ImageDraw


def alien(cell):
    image = Image.new('RGB', (20 * cell, 20 * cell), (255, 255, 255))
    line_width = int(cell * 0.6)
    line_color = (0, 0, 0)
    drawer = ImageDraw.Draw(image)

    # top head
    drawer.arc((3 * cell, 1 * cell, 17 * cell, 15 * cell), start=180, end=360, fill=line_color, width=line_width)
    # bottom head
    drawer.arc((3 * cell, -3 * cell, 17 * cell, 19 * cell), start=0, end=180, fill=line_color, width=line_width)
    # mouth
    drawer.ellipse((9 * cell, 17 * cell, 11 * cell, 18 * cell), fill=line_color)
    # left eye
    drawer.chord((1 * cell, 10 * cell, 9 * cell, 20 * cell), start=270, end=360, fill=line_color)
    drawer.chord((5 * cell, 5 * cell, 13 * cell, 15 * cell), start=90, end=180, fill=line_color)
    drawer.ellipse((6 * cell, 11 * cell, 7 * cell, 12 * cell), fill=(255, 255, 255))
    # right eye
    drawer.chord((11 * cell, 10 * cell, 19 * cell, 20 * cell), start=180, end=270, fill=line_color)
    drawer.chord((7 * cell, 5 * cell, 15 * cell, 15 * cell), start=0, end=90, fill=line_color)
    drawer.ellipse((13 * cell, 11 * cell, 14 * cell, 12 * cell), fill=(255, 255, 255))

    image.save('alien.png')


alien(int(input()))
