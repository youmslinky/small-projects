def validSolution(board):
    def check3x3(x,y):
        threebythree = []
        for i in range(x,x+3):
            threebythree += board[i][y:y+3]
        for n in range(1,10):
            if n not in threebythree:
                return False
        return True

    def checkall3x3():
        for i in range(0,9,3):
            for j in range(0,9,3):
                if not check3x3(i,j):
                    return False
        return True

    def checkCols():
        for i in range(9):
            col = []
            for j in range(9):
                col.append(board[j][i])
            if not (set(col) == set(range(1,10))):
                return False
        return True

    def checkRows():
        for i in range(9):
            if not (set(board[i]) == set(range(1,10))):
                return False
        return True

    for fun in [checkall3x3,checkRows,checkCols]:
        if not fun():
            return False
    return True


goodSudoku = [[5, 3, 4, 6, 7, 8, 9, 1, 2],
              [6, 7, 2, 1, 9, 5, 3, 4, 8],
              [1, 9, 8, 3, 4, 2, 5, 6, 7],
              [8, 5, 9, 7, 6, 1, 4, 2, 3],
              [4, 2, 6, 8, 5, 3, 7, 9, 1],
              [7, 1, 3, 9, 2, 4, 8, 5, 6],
              [9, 6, 1, 5, 3, 7, 2, 8, 4],
              [2, 8, 7, 4, 1, 9, 6, 3, 5],
              [3, 4, 5, 2, 8, 6, 1, 7, 9]]


badSudoku = [[5, 3, 4, 6, 7, 8, 9, 1, 2],
             [6, 7, 2, 1, 9, 0, 3, 4, 9],
             [1, 0, 0, 3, 4, 2, 5, 6, 0],
             [8, 5, 9, 7, 6, 1, 0, 2, 0],
             [4, 2, 6, 8, 5, 3, 7, 9, 1],
             [7, 1, 3, 9, 2, 4, 8, 5, 6],
             [9, 0, 1, 5, 3, 7, 2, 1, 4],
             [2, 8, 7, 4, 1, 9, 6, 3, 5],
             [3, 0, 0, 4, 8, 1, 1, 7, 9]]

print("should be true:",validSolution(goodSudoku))
print("should be false:",validSolution(badSudoku))
