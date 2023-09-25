class Quadratic:
    def __init__(self, a, b, c):
        self.a, self.b, self.c = a, b, c

    def branch(self):
        return ['up', 'down'][self.a < 0]

    def top(self):
        return (-self.b / (2 * self.a), (4 * self.a * self.c - self.b ** 2) / (4 * self.a))

    def y_sect(self):
        return (0, self.c)

    def x_sect(self):
        if (self.top()[1] < 0 and self.branch() == 'up') or (self.top()[1] > 0 and self.branch() == 'down'):
            return 2
        elif self.top()[1] == 0:
            return 1
        else:
            return 0

    def sections(self):
        if (self.top()[1] < 0 and self.branch() == 'up') or (self.top()[1] > 0 and self.branch() == 'down'):
            x1 = (-self.b + ((self.b ** 2 - 4 * self.a * self.c) ** 0.5)) / (2 * self.a)
            x2 = (-self.b - ((self.b ** 2 - 4 * self.a * self.c) ** 0.5)) / (2 * self.a)
            x1, x2 = min(x1, x2), max(x1, x2)
            return (x1, 0.0, x2, 0.0)
        elif self.top()[1] == 0:
            return self.top()
