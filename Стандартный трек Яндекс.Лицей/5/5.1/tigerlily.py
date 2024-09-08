class TigerLily:
    def __init__(self, themes):
        self.themes = list(themes)

    def add_theme(self, value):
        self.themes.append(value)

    def get_themes(self):
        return tuple(self.themes)

    def shift_one(self):
        self.themes = self.themes[-1:] + self.themes[:-1]

    def get_first(self):
        return self.themes[0]

    def reverse_order(self):
        self.themes = self.themes[::-1]