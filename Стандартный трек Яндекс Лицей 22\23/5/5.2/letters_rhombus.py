class LettersRhombus:
    def __init__(self, letter, sep=' '):
        self.letter = letter
        self.sep = sep
        self.max = 1 + 2 * (ord(letter) - ord('A'))

    def rows(self):
        left_right_len = self.max // 2
        center_len = 0
        arr = []
        for i in range(ord(self.letter) - ord('A') + 1):
            char = chr(i + ord('A'))
            left_right = left_right_len * self.sep
            center = center_len * self.sep
            if i == 0:
                arr.append(left_right + char + left_right)
                center_len += 1
                left_right_len -= 1
                continue
            else:
                arr.append(left_right + char + center + char + left_right)
                center_len += 2
                left_right_len -= 1
        arr.extend(arr[:-1][::-1])
        return arr

    def cols(self):
        matrix = [[i for i in row] for row in self.rows()]
        matrix_need = [''.join([matrix[i][j] for i in range(len(matrix))]) for j in range(len(matrix[0]) - 1, -1, -1)]
        return matrix_need
