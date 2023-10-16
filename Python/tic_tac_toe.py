board = [' ' for x in range(10)]


# inserting input to the board
def insertLetter(letter, pos):
    board[pos] = letter


# checks if space is free on board
def spaceIsFree(pos):
    return board[pos] == ' '


# prints the board interface
def printBoard(board):
    print('   |   |   ')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('   |   |   ')
    print('------------')
    print('   |   |   ')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('   |   |   ')
    print('------------')
    print('   |   |   ')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('   |   |   ')


# checks if board is full
def isBoardFull(board):
    if board.count(' ') > 1:
        return False
    else:
        return True


# checks who's the winner
def IsWinner(b, l):
    return ((b[1] == l and b[2] == l and b[3] == l) or
            (b[4] == l and b[5] == l and b[6] == l) or
            (b[7] == l and b[8] == l and b[9] == l) or
            (b[1] == l and b[4] == l and b[7] == l) or
            (b[2] == l and b[5] == l and b[8] == l) or
            (b[3] == l and b[6] == l and b[9] == l) or
            (b[1] == l and b[5] == l and b[9] == l) or
            (b[3] == l and b[5] == l and b[7] == l))


# tracks player's move
def playerMove():
    run = True
    while run:
        move = input("please select a position to enter the X between 1 to 9: ")
        try:
            move = int(move)
            if move > 0 and move < 10:
                if spaceIsFree(move):
                    run = False
                    insertLetter('X', move)
                else:
                    print('Sorry, this space is occupied')
            else:
                print('please type a number between 1 and 9')

        except:
            print('Please type a number')


# tracks computer's move
def computerMove():
    possibleMoves = [x for x, letter in enumerate(board) if letter == ' ' and x != 0]
    move = 0

    for let in ['O', 'X']:
        for i in possibleMoves:
            boardcopy = board[:]
            boardcopy[i] = let
            if IsWinner(boardcopy, let):
                move = i
                return move

    cornersOpen = []
    for i in possibleMoves:
        if i in [1, 3, 7, 9]:
            cornersOpen.append(i)

    if len(cornersOpen) > 0:
        move = selectRandom(cornersOpen)
        return move

    if 5 in possibleMoves:
        move = 5
        return move

    edgesOpen = []
    for i in possibleMoves:
        if i in [2, 4, 6, 8]:
            edgesOpen.append(i)

    if len(edgesOpen) > 0:
        move = selectRandom(edgesOpen)
        return move


# helps computer to choose appropriate move
def selectRandom(li):
    import random
    ln = len(li)
    r = random.randrange(0, ln)
    return li[r]


# main function of the game
def main():
    print("Welcome to the game!")
    printBoard(board)

    while not (isBoardFull(board)):
        if not (IsWinner(board, 'O')):
            playerMove()
            printBoard(board)
        else:
            print("sorry you loose!")
            break

        if not (IsWinner(board, 'X')):
            move = computerMove()
            if move == 0:
                print(" ")
            else:
                insertLetter('O', move)
                print('computer placed an o on position', move, ':')
                printBoard(board)
        else:
            print("you win!")
            break

    if isBoardFull(board):
        print("Tie game")


# message prompt for the player
while True:
    x = input("Do you want to play again? (y/n): ")
    if x.lower() == 'y':
        board = [' ' for x in range(10)]
        print('--------------------')
        main()
    else:
        break
