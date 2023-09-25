class FlowingRectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.square = width * height
        self.k = width / height

    def __add__(self, other):
        self.square += other.square
        self.height = (self.square / self.k) ** 0.5
        self.width = self.height * self.k

    def __sub__(self, other):
        if self.square < other.square:
            self.width, self.height, self.square = 0, 0, 0
        else:
            self.square -= other.square
            self.height = (self.square / self.k) ** 0.5
            self.width = self.height * self.k

    def get_width(self):
        return round(self.width, 2)

    def get_height(self):
        return round(self.height, 2)
