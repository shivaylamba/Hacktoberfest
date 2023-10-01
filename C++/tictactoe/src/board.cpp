#include <iostream>
#include <cstdlib>
#include <cmath>

#include <board.hpp>

void Board::clearScreen()
{
    for(int i = 0; i < 300; i++) {
        std::cout << '\n';
    }
}

char Board::evaluateSymbol(int sym)
{
    switch(sym) {
        case 0:
            return ' ';
        case 1:
            return 'O';
        case 2:
            return 'X';
        default:
            std::cout << "Attempted evaluation of unknown internal symbol" << sym << std::endl;
            exit(EXIT_FAILURE);
    }
}

int Board::evaluateInternalSymbol(char sym)
{
    switch(sym) {
        case ' ':
            return 0;
        case 'O':
            return 1;
        case 'X':
            return 2;
        default:
            std::cout << "Attempted evaluation of unknown symbol" << sym << std::endl;
            exit(EXIT_FAILURE);
    }
}

char Board::isMatching(int pos1, int pos2, int pos3)
{
    if((getSymbol(pos1) == getSymbol(pos2)) && (getSymbol(pos2) == getSymbol(pos3))) {
        return getSymbol(pos1);
    }
    return '0';
}

void Board::drawBoard()
{
    clearScreen();

    std::cout << "Board Pattern: \n 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n\n\n";
    
    std::cout << "You choose X\n" << std::endl;

    std::cout << " " << getSymbol(1) << " | " << getSymbol(2) << " | " << getSymbol(3) << " \n-----------\n "
    << getSymbol(4) << " | " << getSymbol(5) << " | " << getSymbol(6) << " \n-----------\n "
    << getSymbol(7) << " | " << getSymbol(8) << " | " << getSymbol(9) << std::endl;
}

bool Board::isOWinning()
{
    if((isMatching(1, 2, 3) == 'O') || (isMatching(4, 5, 6) == 'O') || (isMatching(7, 8, 9) == 'O') || (isMatching(1, 4, 7) == 'O') || (isMatching(2, 5, 8) == 'O') || (isMatching(3, 6, 9) == 'O') || (isMatching(1, 5, 9) == 'O') || (isMatching(3, 7, 5) == 'O')) {
        return true;
    }
    return false;
}

bool Board::isXWinning()
{
    if((isMatching(1, 2, 3) == 'X') || (isMatching(4, 5, 6) == 'X') || (isMatching(7, 8, 9) == 'X') || (isMatching(1, 4, 7) == 'X') || (isMatching(2, 5, 8) == 'X') || (isMatching(3, 6, 9) == 'X') || (isMatching(1, 5, 9) == 'X') || (isMatching(3, 7, 5) == 'X')) {
        return true;
    }
    return false;
}

void Board::setSymbol(int pos, char symbol)
{
    if((symbol != 'X') && (symbol != 'O') && (symbol != ' ')) {
        std::cout << "Attempt to set unknown symbol " << symbol << " at position " << pos << std::endl;
        exit(EXIT_FAILURE);
    }
    board_state[pos-1] = evaluateInternalSymbol(symbol);
}

char Board::getSymbol(int pos)
{
    if(pos < 1 || pos > 9) {
        std::cout << "Symbol requested from unknown position" << std::endl;
        exit(EXIT_FAILURE);
    }
    return evaluateSymbol(board_state[pos-1]);
}

void Board::playComputer()
{
    int number_of_empty_squares{0};
    for(int i = 0; i < 9; i++) {
        if(board_state[i] == 0) {
            number_of_empty_squares++;
        }
    }
    int index{0};
    int empty_space[number_of_empty_squares];
    for(int i = 0; i < 9; i++) {
        if(board_state[i] == 0) {
            empty_space[index] = i+1;
            index++;
        }
    }

    index = rand()%(number_of_empty_squares) + 1;
    setSymbol(empty_space[index - 1], 'O');

}

bool Board::isDraw()
{
    if((!isXWinning()) && (!isOWinning())) {
        for(int i = 0; i < 9; i++) {
            if(getSymbol(i + 1) == ' ') {
                return false;
            }
        }
        return true;
    }
    return false;
}
