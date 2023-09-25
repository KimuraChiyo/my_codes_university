from PIL import Image, ImageDraw


def weather_vane_orientation(size, bg_color, *vanes):
    image = Image.new('RGB', size, bg_color)
    drawer = ImageDraw.Draw(image)
    for vane in vanes:
        x_center, y_center, type_vane = vane
        a = ((type_vane % 10) * 4) // 2
        start = (x_center - a, y_center - a)
        end = (x_center + a, y_center + a)
        color_square = (type_vane, type_vane, type_vane)
        drawer.rectangle((start, end), fill=color_square)
    return image
