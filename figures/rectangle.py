import random
import helper


class Rectangle:
    def __init__(self, x_=random.randint(1, 100), y_=random.randint(1, 100), x1_=random.randint(1, 100),
                 y1_=random.randint(1, 100), color_code_=random.randint(0, 6)):
        self.name = 'Rectangle'
        self.x = x_
        self.y = y_
        self.y1 = y1_
        self.x1 = x1_
        self.color_code = color_code_

        while self.area() == 0:
            self.x1 = random.randint(1, 100)

        self.calculated_area = self.area()

    def area(self):
        return helper.length(self.x, self.y, self.x1, self.y) * helper.length(self.x, self.y, self.x, self.y1)

    def toString(self):
        return f'{self.name} X: {self.x} Y: {self.y} X1: {self.x1} Y1: {self.y1} S: {self.calculated_area} ' \
               f'Color: {helper.getColorNameByCode(self.color_code)}'
