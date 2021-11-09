import math
import random

import helper


class Circle:
    def __init__(self, x_=random.randint(1, 100), y_=random.randint(1, 100), r_=random.randint(1, 100),
                 color_code_=random.randint(0, 6)):
        self.name = 'Circle'
        self.r = r_
        self.x = x_
        self.y = y_
        self.color_code = color_code_
        self.calculated_area = self.area()

    def area(self):
        return math.pi * self.r * self.r

    def toString(self):
        return f'{self.name} X: {self.x} Y: {self.y} R: {self.r} S: {self.calculated_area} ' \
               f'Color: {helper.getColorNameByCode(self.color_code)}'
