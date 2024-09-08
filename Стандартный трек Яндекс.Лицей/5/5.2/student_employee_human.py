class Student:
    def __init__(self, name, university):
        self.name = name
        self.university = university
        self.course = 1

    def get_name(self):
        return self.name

    def get_university(self):
        return self.university

    def get_year(self):
        return self.course

    def study(self):
        if self.course < 6:
            self.course += 1


class Employee:
    def __init__(self, name, company):
        self.name = name
        self.company = company
        self.positions = ['junior', 'middle', 'senior', 'lead']
        self.index = 0

    def get_name(self):
        return self.name

    def get_company(self):
        return self.company

    def work(self):
        if self.index < 3:
            self.index += 1

    def get_position(self):
        return self.positions[self.index]


class Human:
    def __init__(self, name):
        self.name = name

    def get_name(self):
        return self.name
