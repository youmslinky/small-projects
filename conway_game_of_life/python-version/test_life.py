from life import *
import random


def test_1d_cells():
    nothinginit = [[0 for j in range(0, 4)]]
    for i in range(1, 4):
        gen = random.randrange(1, 20, 1)
        assert get_generation(nothinginit, gen) == nothinginit


def test_nothing():
    nothinginit = [0 for j in range(0, 4)]
    nothinginit[0] = [0, 0, 0, 0]
    nothinginit[1] = [0, 0, 0, 0]
    nothinginit[2] = [0, 0, 0, 0]
    nothinginit[3] = [0, 0, 0, 0]
    for i in range(1, 4):
        gen = random.randrange(1, 20, 1)
        assert get_generation(nothinginit, gen) == nothinginit


def test_block_wrap():
    blockinit = [0 for j in range(0, 4)]

    blockinit[0] = [1, 0, 0, 1]
    blockinit[1] = [0, 0, 0, 0]
    blockinit[2] = [0, 0, 0, 0]
    blockinit[3] = [1, 0, 0, 1]

    for i in range(1, 4):
        gen = random.randrange(1, 20, 1)
        assert get_generation(blockinit, gen) == blockinit
        print("block %sth generation fails" % gen, "block %sth generations" % gen)


def test_block_nowrap():
    blockinit = [0 for j in range(0, 4)]

    blockinit[0] = [1, 0, 0, 1]
    blockinit[1] = [0, 0, 0, 0]
    blockinit[2] = [0, 0, 0, 0]
    blockinit[3] = [1, 0, 0, 1]

    result = [0 for j in range(0, 4)]

    result[0] = [0, 0, 0, 0]
    result[1] = [0, 0, 0, 0]
    result[2] = [0, 0, 0, 0]
    result[3] = [0, 0, 0, 0]
    assert get_generation(blockinit, 1, wrap=False) == result


def test_glider():
    gliderinit = [0 for j in range(0, 5)]
    gliderinit[0] = [0, 0, 0, 0, 0]
    gliderinit[1] = [0, 0, 1, 0, 0]
    gliderinit[2] = [0, 0, 0, 1, 0]
    gliderinit[3] = [0, 1, 1, 1, 0]
    gliderinit[4] = [0, 0, 0, 0, 0]

    glider12gen = [0 for j in range(0, 5)]
    glider12gen[0] = [0, 1, 0, 0, 0]
    glider12gen[1] = [1, 1, 0, 0, 1]
    glider12gen[2] = [0, 0, 0, 0, 0]
    glider12gen[3] = [0, 0, 0, 0, 0]
    glider12gen[4] = [1, 0, 0, 0, 0]

    assert get_generation(gliderinit, 12) == glider12gen
    print("glider 12th generation fails")


def test_blinker():
    blinkerinit = [0 for j in range(0, 5)]
    blinkerinit[0] = [0, 0, 0, 0, 0]
    blinkerinit[1] = [0, 0, 0, 0, 0]
    blinkerinit[2] = [0, 1, 1, 1, 0]
    blinkerinit[3] = [0, 0, 0, 0, 0]
    blinkerinit[4] = [0, 0, 0, 0, 0]

    blinker12gen = [0 for j in range(0, 5)]
    blinker12gen[0] = [0, 0, 0, 0, 0]
    blinker12gen[1] = [0, 0, 1, 0, 0]
    blinker12gen[2] = [0, 0, 1, 0, 0]
    blinker12gen[3] = [0, 0, 1, 0, 0]
    blinker12gen[4] = [0, 0, 0, 0, 0]

    assert get_generation(blinkerinit, 1) == blinker12gen
    assert get_generation(blinkerinit, 2) == blinkerinit
    print("glider 12th generation fails")


def test_wrap_index_normal_range():
    for i in [0, 1, 2, 3]:
        assert wrap_index(i, 10) == i


def test_wrap_index_outside_range_positive():
    assert wrap_index(10, 10) == 0
    assert wrap_index(11, 10) == 1
    assert wrap_index(12, 10) == 2


def test_wrap_index_outside_range_negative():
    assert wrap_index(-1, 10) == 9
    assert wrap_index(-2, 10) == 8
    assert wrap_index(-3, 10) == 7


def test_get_width_height_0x0():
    assert get_width_height([]) == (0, 0)


def test_get_width_height_1x1():
    assert get_width_height([0]) == (1, 1)


def test_get_width_height_2x1():
    assert get_width_height([0, 0]) == (2, 1)


def test_get_width_height_2x3():
    assert get_width_height([[0, 0], [0, 0], [0, 0]]) == (2, 3)


def test_get_width_height_3x2():
    assert get_width_height([[0, 0, 0], [0, 0, 0]]) == (3, 2)


# wrap=False
def test_neighbor_counts_nowrap_empty_1x1():
    cells = [[0]]
    assert neighbor_counts(cells, wrap=False) == cells


def test_neighbor_counts_nowrap_empty_3x1():
    cells = [[0, 0, 0]]
    assert neighbor_counts(cells, wrap=False) == cells


def test_neighbor_counts_nowrap_empty_3x2():
    cells = [[0, 0, 0], [0, 0, 0]]
    assert neighbor_counts(cells, wrap=False) == cells


def test_neighbor_counts_nowrap_filled_3x3():
    cells = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]
    counts = [[3, 5, 3], [5, 8, 5], [3, 5, 3]]
    assert neighbor_counts(cells, wrap=False) == counts


def test_neighbor_counts_nowrap_filled_3x2():
    cells = [[1, 1, 1], [1, 1, 1]]
    counts = [[3, 5, 3], [3, 5, 3]]
    assert neighbor_counts(cells, wrap=False) == counts


def test_neighbor_counts_nowrap_single_3x3():
    cells = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
    counts = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    assert neighbor_counts(cells, wrap=False) == counts


def test_neighbor_counts_nowrap_blinker():
    cells = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]

    counts = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 1, 2, 3, 2, 1, 0],
        [0, 1, 1, 2, 1, 1, 0],
        [0, 1, 2, 3, 2, 1, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]
    assert neighbor_counts(cells, wrap=False) == counts


# wrap=True
def test_neighbor_counts_wrap_empty_1x1():
    cells = [[0]]
    assert neighbor_counts(cells) == cells


def test_neighbor_counts_wrap_empty_3x1():
    cells = [[0, 0, 0]]
    assert neighbor_counts(cells) == cells


def test_neighbor_counts_wrap_empty_3x2():
    cells = [[0, 0, 0], [0, 0, 0]]
    assert neighbor_counts(cells) == cells


def test_neighbor_counts_wrap_filled_3x3():
    cells = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]
    counts = [[8, 8, 8], [8, 8, 8], [8, 8, 8]]
    assert neighbor_counts(cells) == counts


def test_neighbor_counts_wrap_filled_3x2():
    cells = [[1, 1, 1], [1, 1, 1]]
    counts = [[8, 8, 8], [8, 8, 8]]
    assert neighbor_counts(cells) == counts


def test_neighbor_counts_wrap_single_3x3():
    cells = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
    counts = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    assert neighbor_counts(cells) == counts


def test_neighbor_counts_wrap_blinker():
    cells = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]

    counts = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 1, 2, 3, 2, 1, 0],
        [0, 1, 1, 2, 1, 1, 0],
        [0, 1, 2, 3, 2, 1, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]
    assert neighbor_counts(cells) == counts


def test_get_next_state_survive():
    assert get_next_state(1, 2) == 1
    assert get_next_state(1, 3) == 1


def test_get_next_state_birth():
    assert get_next_state(0, 3) == 1


def test_get_next_state_death():
    assert get_next_state(0, 0) == 0
    assert get_next_state(0, 1) == 0
    assert get_next_state(0, 2) == 0
    assert get_next_state(0, 4) == 0
    assert get_next_state(0, 5) == 0
    assert get_next_state(0, 6) == 0
    assert get_next_state(0, 7) == 0
    assert get_next_state(0, 8) == 0
    assert get_next_state(1, 0) == 0
    assert get_next_state(1, 1) == 0
    assert get_next_state(1, 4) == 0
    assert get_next_state(1, 5) == 0
    assert get_next_state(1, 6) == 0
    assert get_next_state(1, 7) == 0
    assert get_next_state(1, 8) == 0
