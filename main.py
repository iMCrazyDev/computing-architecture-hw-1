import random
import sys
import time

from figures.circle import Circle
from figures.rectangle import Rectangle
from figures.triagnle import Triangle

ERROR_UNKNOWN_ARGS = 'incorrect qualifier value!\n Waited:\n command -f infile outfile01 outfile02\nOr:\ncommand -n ' \
                     'number outfile01 outfile02\n '


def readArray(file_name):
    input_file = open(file_name, "r")
    cont = []
    while True:
        line = input_file.readline().split(' ')
        if line == ['']:
            break

        if line[0] == '1':
            a = Rectangle(int(line[1]), int(line[2]), int(line[3]), int(line[4]), int(line[5]))
            cont.append(a)
        elif line[0] == '2':
            a = Triangle(int(line[1]), int(line[2]), int(line[3]), int(line[4]), int(line[5]), int(line[6]),
                         int(line[7]))
            cont.append(a)
        elif line[0] == '3':
            a = Circle(int(line[1]), int(line[2]), int(line[3]), int(line[4]))
            cont.append(a)

    return cont


def generateArray(sz):
    cont = []
    for i in range(sz):
        rnd = random.randint(0, 2)

        if rnd == 0:
            a = Rectangle()
            cont.append(a)
        elif rnd == 1:
            a = Triangle()
            cont.append(a)
        else:
            a = Circle()
            cont.append(a)

    return cont


def sortContainer(cont):
    for i in range(1, len(cont)):
        el = cont[i]
        j = i - 1
        while j >= 0 and cont[j].calculated_area > el.calculated_area:
            cont[j + 1] = cont[j]
            j -= 1

        cont[j + 1] = el


if __name__ == '__main__':
    start_time = time.time()
    args = sys.argv
    container = []

    print('Start')
    if len(args) < 5:
        print(ERROR_UNKNOWN_ARGS)
        exit(1)
    if args[1] == '-f':
        container = readArray(args[2])
    elif args[1] == '-n':
        size = int(args[2])

        if size < 0:
            print("Incorrect number of figures")
            exit(2)

        container = generateArray(size)
    else:
        print(ERROR_UNKNOWN_ARGS)
        exit(1)

    area_sum = 0

    for x in container:
        area_sum += x.calculated_area

    outfile = open(args[3], "w")
    outfile.write(str(len(container)) + '\n')
    outfile.write(f'Sum {area_sum}\n')

    for x in container:
        outfile.write(x.toString())
        outfile.write('\n')
    outfile.close()

    sortContainer(container)

    outfile_sorted = open(args[4], "w")
    outfile_sorted.write(f'Sum {area_sum}\n')
    outfile_sorted.write(str(len(container)) + '\n')

    for x in container:
        outfile_sorted.write(x.toString())
        outfile_sorted.write('\n')
    outfile_sorted.close()
    finish_time = time.time()
    print(f'{finish_time - start_time:.10f}s')
    print('Stop')

