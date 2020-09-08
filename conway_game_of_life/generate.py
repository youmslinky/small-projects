import random

import life
from print_life import cells2String


def check_if_static(cells, wrap=True):
    next_state = life.get_generation(cells, 1, wrap=wrap)
    return next_state == cells


def random_cells(width, height):
    return [[random.choice([0, 1]) for j in range(0, width)] for i in range(0, height)]


def gen_static(width, height, wrap=False):
    candidate = random_cells(width, height)
    while not check_if_static(surround_with_zeros(candidate), wrap):
        candidate = random_cells(width, height)
    return candidate


def surround_with_zeros(cells):
    if cells == [[]]:
        return [[]]
    else:
        width = len(cells[0]) + 2
        result = [[0 for j in range(0, width)]]
        for row in cells:
            result.append([0] + row + [0])
        result.append([0 for j in range(0, width)])
        return result


if __name__ == "__main__":
    for i in range(10):
        print(cells2String(gen_static(4, 4)))
