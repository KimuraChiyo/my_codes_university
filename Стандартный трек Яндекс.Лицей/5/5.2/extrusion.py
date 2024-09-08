from math import pi


class Square:
    def __init__(self, side):
        self.side = side

    def extrude(self, h):
        return self.side * self.side * h


class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def extrude(self, h):
        return self.width * self.height * h


class Triangle:
    def __init__(self, side):
        self.side = side

    def extrude(self, h):
        return (self.side * self.side * (3 ** 0.5) * h) / 4


class Circle:
    def __init__(self, radius):
        self.radius = radius

    def extrude(self, h):
        return self.radius ** 2 * pi * h
