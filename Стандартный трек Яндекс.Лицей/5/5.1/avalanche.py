class Avalanche:
    def __init__(self):
        self.curr = 'O'

    def go(self):
        print(self.curr)
        self.curr = ''.join(['oOo' if i == 'o' else 'ooOoo' for i in self.curr])
