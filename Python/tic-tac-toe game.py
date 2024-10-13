# Function to print the board
def print_board(board):
    print("\n")
    for row in board:
        print(" | ".join(row))
        print("-" * 9)
    print("\n")

# Function to check for a winner
def check_winner(board, player):
    # Check rows, columns, and diagonals
    for i in range(3):
        # Check rows and columns
        if all([spot == player for spot in board[i]]) or all([board[j][i] == player for j in range(3)]):
            return True
    # Check diagonals
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2 - i] == player for i in range(3)]):
        return True
    return False

# Function to check for a draw
def check_draw(board):
    return all([spot != " " for row in board for spot in row])

# Function to get a player's move
def get_move(board, player):
    while True:
        try:
            move = int(input(f"Player {player}, enter your move (1-9): ")) - 1
            if move < 0 or move >= 9:
                print("Invalid move. Please enter a number between 1 and 9.")
                continue
            row, col = divmod(move, 3)
            if board[row][col] == " ":
                return row, col
            else:
                print("That spot is already taken. Try again.")
        except ValueError:
            print("Invalid input. Please enter a number.")

# Main game loop
def play_game():
    # Initialize the board
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"
    
    # Loop until the game ends
    while True:
        print_board(board)
        
        # Get the current player's move
        row, col = get_move(board, current_player)
        board[row][col] = current_player
        
        # Check for a win
        if check_winner(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            break
        
        # Check for a draw
        if check_draw(board):
            print_board(board)
            print("It's a draw!")
            break
        
        # Switch player
        current_player = "O" if current_player == "X" else "X"

# Uncomment the line below to play the game
#play_game()
