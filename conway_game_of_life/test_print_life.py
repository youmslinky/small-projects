from print_life import *

def test_print_cells_nothing():
    assert cells2String([[]]) == "\n"
def test_print_cells_single_alive():
    cells = [[1]]
    assert cells2String(cells) == "█\n"
def test_print_cells_single_dead():
    cells = [[0]]
    assert cells2String(cells) == "░\n"
def test_print_cells_2x2_dead():
    cells = [[0,0],[0,0]]
    result = "░░\n░░\n"
    assert cells2String(cells) == result
def test_print_cells_2x2_alive():
    cells = [[1,1],[1,1]]
    result = "██\n██\n"
    assert cells2String(cells) == result
def test_print_cells_2x2_half():
    cells = [[1,0],[0,1]]
    result = "█░\n░█\n"
    assert cells2String(cells) == result
