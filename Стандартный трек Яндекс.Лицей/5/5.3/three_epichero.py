def less(self, other):
    return True if (self.win_count < other.win_count) or (self.win_count == other.win_count and
                                                          len(self.weapons) < len(other.weapons)) \
                   or (self.win_count == other.win_count and len(self.weapons) == len(other.weapons)
                       and len(self.name) > len(other.name)) else False


def equal(self, other):
    return True if (self.win_count == self.win_count and len(self.weapons) == len(other.weapons) and
                    len(self.name) == len(other.name) and self.name == other.name) else False


class EpicHero:
    def __init__(self, name, win_count, weapons):
        self.name = name
        self.win_count = win_count
        self.weapons = sorted(weapons)

    def __str__(self):
        return f'Epic Hero {self.name}, {self.win_count}'

    def __repr__(self):
        return f"EpicHero('{self.name}', {self.win_count}, {self.weapons})"

    def add_win(self):
        self.win_count += 1

    def add_weapon(self, weapon):
        self.weapons.append(weapon)
        self.weapons.sort()

    def del_weapon(self, weapon):
        if weapon in self.weapons:
            del self.weapons[self.weapons.index(weapon)]

    def __lt__(self, other):
        '''<'''
        return less(self, other)

    def __le__(self, other):
        '''<='''
        return less(self, other) or equal(self, other)

    def __gt__(self, other):
        '''>'''
        return not (less(self, other) or equal(self, other))

    def __ge__(self, other):
        '''>='''
        return not less(self, other)

    def __eq__(self, other):
        '''=='''
        return equal(self, other)

    def __ne__(self, other):
        '''!='''
        return not equal(self, other)
