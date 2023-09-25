def print_hist(arr):
    for i in arr:
        print('*' * i)


class TwoHandedSawUp:
    def __init__(self, arr):
        self.arr = arr[:]
        self.lenght = len(self.arr)

    def sawing(self):
        self.arr.sort()
        if self.lenght % 2:
            less = self.arr[:self.lenght // 2 + 1]
            more = self.arr[self.lenght // 2 + 1:]
        else:
            less = self.arr[:self.lenght // 2]
            more = self.arr[self.lenght // 2:]
        self.arr = []
        for i in range(self.lenght):
            if not i % 2:
                self.arr.append(less.pop(0))
            else:
                self.arr.append(more.pop(0))

    def get_list(self):
        return self.arr


class TwoHandedSawDown:
    def __init__(self, arr):
        self.arr = arr[:]
        self.lenght = len(self.arr)

    def sawing(self):
        self.arr.sort()
        less = self.arr[:self.lenght // 2][::-1]
        more = self.arr[self.lenght // 2:][::-1]
        self.arr = []
        for i in range(self.lenght):
            if not i % 2:
                self.arr.append(more.pop(0))
            else:
                self.arr.append(less.pop(0))

    def get_list(self):
        return self.arr
