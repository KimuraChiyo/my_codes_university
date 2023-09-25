from PIL import Image


def reflect(filename, kind=1):
    image = Image.open(filename)
    types = [image.transpose(Image.FLIP_TOP_BOTTOM),
             image.transpose(Image.FLIP_LEFT_RIGHT),
             image.transpose(Image.ROTATE_180)]
    image = types[kind - 1]
    image.save("result.png")
