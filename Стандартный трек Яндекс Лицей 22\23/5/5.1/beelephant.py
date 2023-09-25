class BeeElephant:
    def __init__(self, bee, elephant):
        self.bee = bee
        self.elephant = elephant

    def fly(self):
        return self.bee >= self.elephant

    def trumpet(self):
        return 'tu-tu-doo-doo!' if self.elephant >= self.bee else 'wzzzzz'

    def eat(self, meal, value):
        if meal == 'nectar':
            self.elephant -= value
            self.bee += value
        elif meal == 'grass':
            self.bee -= value
            self.elephant += value
        if self.elephant > 100:
            self.elephant = 100
        elif self.elephant < 0:
            self.elephant = 0
        if self.bee > 100:
            self.bee = 100
        elif self.bee < 0:
            self.bee = 0

    def get_parts(self):
        return (self.bee, self.elephant)
