class ModifiedString:
    def __init__(self, string):
        self.string = string

    def __add__(self, other):
        return ModifiedString(self.string + other)

    def __radd__(self, other):
        return ModifiedString(other + self.string)

    def __sub__(self, other):
        other = set(other)
        string = self.string
        for i in other:
            string = string.replace(i, '')
            string = string.replace(i.swapcase(), '')
        return ModifiedString(string)

    def __rsub__(self, other):
        self_set = set(self.string)
        for i in self_set:
            other = other.replace(i, '')
            other = other.replace(i.swapcase(), '')
        return ModifiedString(other)

    def __str__(self):
        return self.string
