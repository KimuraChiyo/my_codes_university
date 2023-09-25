class EulerNumber:
    def __init__(self, n):
        self.n = n

    def get_number(self, x=1):
        num = 0
        top, bottom = 1, 1
        for i in range(1, self.n + 1):
            num += top / bottom
            top *= x
            bottom *= i
        return num
