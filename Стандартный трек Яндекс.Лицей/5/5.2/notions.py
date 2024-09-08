class ShoppingList:
    def __init__(self, *tpls):
        self.tpls = list(tpls)

    def values(self):
        return self.tpls

    def append(self, appending):
        self.tpls.append((appending, False))

    def check(self, checking):
        for pos in range(len(self.tpls)):
            if self.tpls[pos][0] == checking:
                self.tpls[pos] = (checking, True)

    def checked_values(self):
        return [self.tpls[i] for i in range(len(self.tpls)) if self.tpls[i][1]]

    def rest_values(self):
        return [self.tpls[i] for i in range(len(self.tpls)) if not self.tpls[i][1]]


class TODOList:
    def __init__(self, *tpls):
        self.tpls = list(tpls)

    def values(self):
        self.tpls = sorted(self.tpls, key=lambda x: -x[1])
        return self.tpls

    def append(self, value, urgency):
        self.tpls.append((value, urgency, False))
        self.tpls = sorted(self.tpls, key=lambda x: -x[1])

    def check(self, checking):
        for pos in range(len(self.tpls)):
            if self.tpls[pos][0] == checking:
                self.tpls[pos] = (checking, self.tpls[pos][1], True)

    def checked_values(self):
        return [self.tpls[i] for i in range(len(self.tpls)) if self.tpls[i][2]]

    def rest_values(self):
        return [self.tpls[i] for i in range(len(self.tpls)) if not self.tpls[i][2]]


class Route:
    def __init__(self, *tpls):
        self.tpls = list(tpls)

    def values(self):
        return self.tpls

    def append(self, place, time):
        if len(self.tpls) == 0 or time > self.tpls[-1][1]:
            self.tpls.append((place, time, False))

    def check(self, checking):
        for pos in range(len(self.tpls)):
            if self.tpls[pos][0] == checking:
                self.tpls[pos] = (checking, self.tpls[pos][1], True)

    def checked_values(self):
        return [self.tpls[i] for i in range(len(self.tpls)) if self.tpls[i][2]]

    def rest_values(self):
        return [self.tpls[i] for i in range(len(self.tpls)) if not self.tpls[i][2]]
