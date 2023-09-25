class JamesWebb:
    def __init__(self, data):
        self.data = data
        self.s = 0
        self.g = 0
        self.v = 0
        for lst in data:
            for value in lst:
                if value > 0:
                    self.g += 1
                elif value == 0:
                    self.v += 1
                elif value < 0:
                    self.s += 1

    def brightest_star(self):
        need = {}
        for i in range(len(self.data)):
            for j in range(len(self.data[0])):
                if self.data[i][j] < 0:
                    need[(i, j)] = self.data[i][j]
        need = sorted(need.items(), key=lambda x: (x[1], x[0][0], x[0][1]))
        return need[0][0]

    def brightest_galaxy(self):
        need = {}
        for i in range(len(self.data)):
            for j in range(len(self.data[0])):
                if self.data[i][j] > 0:
                    need[(i, j)] = self.data[i][j]
        need = sorted(need.items(), key=lambda x: (-x[1], x[0][0], x[0][1]))
        return need[0][0]

    def stars(self):
        return self.s

    def galaxies(self):
        return self.g

    def voids(self):
        return self.v
