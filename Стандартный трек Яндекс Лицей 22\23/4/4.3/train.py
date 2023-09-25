from PIL import Image, ImageDraw
from PIL.ImageColor import getrgb


def train(out_filename):
    size = (280, 200)
    x, y = size
    image = Image.new("RGB", size, "#ccecff")
    drawer = ImageDraw.Draw(image)
    drawer.rectangle(((40, y - 90), (80, y - 50)), getrgb("#c55a11"))
    drawer.rectangle(((80, y - 110), (160, y - 50)), getrgb("#0070c0"))
    drawer.rectangle(((160, y - 150), (240, y - 50)), getrgb("#548235"))
    drawer.rectangle(((150, y - 160), (250, y - 150)), getrgb("#c55a11"))
    drawer.rectangle(((80, y - 140), (110, y - 110)), (255, 0, 0))
    drawer.rectangle(((185, y - 140), (215, y - 100)), (255, 255, 255))
    drawer.polygon(((40, y - 90),
                    (60, y - 125),
                    (80, y - 90)), getrgb('#ffc000'))
    drawer.polygon(((80, y - 140),
                    (95, y - 166),
                    (110, y - 140)), getrgb('#ffc000'))
    drawer.ellipse(((80, y - 60), (110, y - 30)), (0, 0, 0))
    drawer.ellipse(((120, y - 70), (160, y - 30)), (0, 0, 0))
    drawer.ellipse(((180, y - 70), (220, y - 30)), (0, 0, 0))

    image.save(out_filename)
