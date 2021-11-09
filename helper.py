def length(x, y, x1, y1):
    return ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5


def calculateTriangleArea(x, y, x1, y1, x2, y2):
    a = length(x, y, x1, y1)
    b = length(x, y, x2, y2)
    c = length(x1, y1, x2, y2)
    p = (a + b + c) / 2

    return (p * (p - a) * (p - b) * (p - c)) ** 0.5


colors = ['RED', 'ORANGE', 'YELLOW', 'GREEN', 'LIGHT_BLUE', 'BLUE', 'VIOLET']


def getColorNameByCode(code):
    return colors[code];
