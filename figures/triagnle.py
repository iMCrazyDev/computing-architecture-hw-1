import random
import helper


class Triangle:
    def __init__(self, x_=random.randint(1, 100), y_=random.randint(1, 100),
                 x1_=random.randint(1, 100), y1_=random.randint(1, 100), x2_=random.randint(1, 100),
                 y2_=random.randint(1, 100), color_code_=random.randint(0, 6)):
        self.name = 'Triangle'
        self.x = x_
        self.x1 = x1_
        self.x2 = x2_
        self.y = y_
        self.y1 = y1_
        self.y2 = y2_
        self.color_code = color_code_

        while self.area() == 0:
            self.x2 = random.randint(1, 100)

        self.calculated_area = self.area()

    def area(self):
        return helper.calculateTriangleArea(self.x, self.y, self.x1, self.y1, self.x2, self.y2)

    def toString(self):
        return f'{self.name} X: {self.x} Y: {self.y} X1: {self.x1} Y1: {self.y1} X2: {self.x2} Y2: {self.y2} ' \
               f'S: {self.calculated_area} Color: {helper.getColorNameByCode(self.color_code)}'

