from PIL import Image


def snow_forest(coords, percent):
    k = percent / 100

    snow_image = Image.open('snow.png')
    snow_image = snow_image.resize((100, 100))
    snow_image_pixels = snow_image.load()

    forest_image = Image.open('forest.png')
    forest_image_pixels = forest_image.load()
    x, y = forest_image.size

    for i in range(x):
        for j in range(y):
            if coords[0] <= i <= coords[0] + 99 and coords[1] <= j <= coords[1] + 99:
                r1, g1, b1 = snow_image_pixels[i - coords[0], j - coords[1]]
                r2, g2, b2 = forest_image_pixels[i, j]
                r, g, b = int(r1 * k + r2 * (1 - k)), int(g1 * k + g2 * (1 - k)), int(b1 * k + b2 * (1 - k))
                forest_image_pixels[i, j] = r, g, b

    forest_image.save("output.png")