from PIL import Image


def color_gradient(out_filename, coordinates, kind='linear', color='r'):
    if kind == 'linear':
        image = Image.linear_gradient('L').convert('RGB')
        pixels = image.load()
        x, y = image.size

        for i in range(x):
            for j in range(y):
                r, g, b = pixels[i, j]
                if color == "r":
                    pixels[i, j] = r, 0, 0
                elif color == "g":
                    pixels[i, j] = 0, g, 0
                elif color == "b":
                    pixels[i, j] = 0, 0, b

    elif kind == 'radial':
        image = Image.radial_gradient('L').convert('RGB')
        pixels = image.load()
        x, y = image.size

        for i in range(x):
            for j in range(y):
                r, g, b = pixels[i, j]
                if color == "r":
                    pixels[i, j] = r, 0, 0
                elif color == "g":
                    pixels[i, j] = 0, g, 0
                elif color == "b":
                    pixels[i, j] = 0, 0, b

    image = image.crop(coordinates)
    image.save(out_filename)
