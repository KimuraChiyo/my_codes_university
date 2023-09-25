from math import pi


class SquareIntoCircle:
    def __init__(self, side):
        self.side = side

    def size(self):
        return round(2 * self.side / pi, 3)

    def area(self):
        return round(4 / pi * self.side * self.side, 3)


class CircleIntoSquare:
    def __init__(self, radius):
        self.radius = radius

    def size(self):
        return round(pi * self.radius / 2, 3)

    def area(self):
        return round(pi * pi * self.radius * self.radius / 4, 3)
