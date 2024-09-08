class PearsBasket:
    def __init__(self, count):
        self.count = count

    def __floordiv__(self, other):
        if self.count == 0:
            return [PearsBasket(0)] * other
        elif self.count < other:
            return [PearsBasket(0)] * other + [PearsBasket(self.count % other)]
        elif self.count % other == 0:
            return [PearsBasket(self.count // other)] * other
        elif self.count % other > 0:
            return [PearsBasket(self.count // other)] * other + [PearsBasket(self.count % other)]

    def __mod__(self, other):
        return self.count % other

    def __add__(self, other):
        return PearsBasket(self.count + other.count)

    def __sub__(self, other):
        if self.count > other:
            self.count -= other
        else:
            self.count = 0

    def __str__(self):
        return str(self.count)

    def __repr__(self):
        return f"PearsBasket({self.count})"
