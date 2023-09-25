class Talking:
    def __init__(self, name):
        self.name = name
        self.counter_yes = 0
        self.counter_no = 0
        self.counter = 0

    def to_answer(self):
        self.counter += 1
        if self.counter % 2:
            self.counter_yes += 1
        else:
            self.counter_no += 1
        return ['moore-moore', 'meow-meow'][(self.counter - 1) % 2]

    def number_yes(self):
        return str(self.counter_yes)

    def number_no(self):
        return str(self.counter_no)
