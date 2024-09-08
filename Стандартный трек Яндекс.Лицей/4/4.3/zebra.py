from PIL import Image, ImageDraw


def stripes(count_lines, size, direction='v'):
    image = Image.new("RGB", size, (0, 0, 0))
    x, y = image.size
    draw = ImageDraw.Draw(image)
    if direction == 'v':
        width = x // count_lines
        start = width // 2
        for i in range(count_lines):
            color = (255, 255, 255) if i % 2 else (0, 0, 0)
            draw.rectangle(((i * width, 0), (i * width + width, y)), color)

    elif direction == 'h':
        width = y // count_lines
        start = width // 2
        for i in range(count_lines):
            color = (255, 255, 255) if i % 2 else (0, 0, 0)
            draw.rectangle(((0, i * width), (x, i * width + width)), color)

    image.save('zebra.png')
