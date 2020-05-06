from generate import *
def test_check_static_nothing():
    assert check_if_static([[]]) == True
def test_check_static_1x1_alive():
    assert check_if_static([[1]]) == False
def test_check_static_1x1_dead():
    assert check_if_static([[0]]) == True
def test_check_static_block_wrapped():
    blockinit = [0 for j in range(0, 4)]
    blockinit[0] = [1, 0, 0, 1]
    blockinit[1] = [0, 0, 0, 0]
    blockinit[2] = [0, 0, 0, 0]
    blockinit[3] = [1, 0, 0, 1]
    assert check_if_static(blockinit) == True
def test_check_static_block():
    blockinit = [0 for j in range(0, 4)]
    blockinit[0] = [0, 0, 0, 0]
    blockinit[1] = [0, 1, 1, 0]
    blockinit[2] = [0, 1, 1, 0]
    blockinit[3] = [0, 0, 0, 0]
    assert check_if_static(blockinit) == True
def test_check_static_blinker():
    blinkerinit = [0 for j in range(0, 5)]
    blinkerinit[0] = [0, 0, 0, 0, 0]
    blinkerinit[1] = [0, 0, 0, 0, 0]
    blinkerinit[2] = [0, 1, 1, 1, 0]
    blinkerinit[3] = [0, 0, 0, 0, 0]
    blinkerinit[4] = [0, 0, 0, 0, 0]
    assert check_if_static(blinkerinit) == False
def test_check_static_glider():
    gliderinit = [0 for j in range(0, 5)]
    gliderinit[0] = [0, 0, 0, 0, 0]
    gliderinit[1] = [0, 0, 1, 0, 0]
    gliderinit[2] = [0, 0, 0, 1, 0]
    gliderinit[3] = [0, 1, 1, 1, 0]
    gliderinit[4] = [0, 0, 0, 0, 0]
    assert check_if_static(gliderinit) == False

def test_random_cells_size():
    result = random_cells(2,3)
    print(result)
    assert len(result) == 3
    assert len(result[0]) == 2

def test_surround_with_zeros_0x0():
    cells = [[]]
    result = [[]]
    assert surround_with_zeros(cells) == result

def test_surround_with_zeros_1x1():
    cells = [[1]]
    result = [[0,0,0],[0,1,0],[0,0,0]]
    assert surround_with_zeros(cells) == result

def test_surround_with_zeros_2x2():
    cells = [[1,0],[0,1]]
    result = [[0,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,0]]
    assert surround_with_zeros(cells) == result
