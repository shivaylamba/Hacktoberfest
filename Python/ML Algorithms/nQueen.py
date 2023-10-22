n = 12 # Size of the chessboard and number of queens

def print_board(board):
    for row in board:
        print(row)
    print()

board = [[0 for _ in range(n)] for _ in range(n)]

def is_safe(board, row, col):
    # Check the row
    for i in range(col):
        if board[row][i] == 1:
            return False
    
     #Check the col
    for i in range(row):
        if board[i][col] == 1:
            return False
    
    # Check upper left diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check lower left diagonal
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check upper right diagonal
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 1:
            return False
    
    # Check lower right diagonal
    for i, j in zip(range(row, n, 1), range(col, n)):
        if board[i][j] == 1:
            return False
    
    return True

def solve_nqueens(board, col):
    if col >= n:
        return True
    
    for i in range(n):
        if is_safe(board, i, col):
            board[i][col] = 1.
            if solve_nqueens(board, col + 1):
                return True
            board[i][col] = 0
    
    return False

if solve_nqueens(board, 0):
    print_board(board)
else:
    print("Solution not found")
