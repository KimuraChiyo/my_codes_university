class BlackCat:
    def __init__(self, name):
        self.name = name
        self.wools = 0
        self.tails = 0

    def play(self, kind, n):
        if kind != 'tail' and kind != 'wool':
            self.wools = 0
            self.tails = 0
        elif kind == 'tail':
            self.tails += n
        elif kind == 'wool':
            self.wools += n

    def get_play(self):
        return (self.wools, self.tails)
