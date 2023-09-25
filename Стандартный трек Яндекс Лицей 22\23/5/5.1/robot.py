class Robot:
    def __init__(self, coords):
        self.x, self.y = coords
        self.last_move = []
        self.last_move.append((self.x, self.y))

    def move(self, seq):
        self.last_move = []
        self.last_move.append((self.x, self.y))
        for move in seq:
            if move == 'N':
                self.y += 1
            elif move == 'S':
                self.y -= 1
            elif move == 'E':
                self.x += 1
            elif move == 'W':
                self.x -= 1
            self.last_move.append((self.x, self.y))
        return (self.x, self.y)

    def path(self):
        return self.last_move
