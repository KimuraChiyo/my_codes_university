class RightMirror:
    def __init__(self, matrix):
        self.matrix = matrix[:]

    def reflect(self):
        for i in range(len(self.matrix)):
            self.matrix[i] = self.matrix[i][::-1]


class BottomMirror:
    def __init__(self, matrix):
        self.matrix = matrix[:]

    def reflect(self):
        self.matrix = self.matrix[::-1]
