class LineToTable:
    def __init__(self, lst_line, rows, cols):
        self.lst_line = lst_line
        self.rows = rows
        self.cols = cols

    def resize(self):
        matrix = [[0] * self.cols for i in range(self.rows)]
        for i in range(self.rows):
            for j in range(self.cols):
                matrix[i][j] = self.lst_line[i * self.cols + j]
        return matrix, self.rows, self.cols


class TableToLine:
    def __init__(self, matrix):
        self.matrix = matrix
        self.rows = len(matrix)
        self.cols = len(matrix[0])

    def resize(self):
        line = []
        for i in self.matrix:
            line.extend(i)
        return line, self.rows, self.cols
