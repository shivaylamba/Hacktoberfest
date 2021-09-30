// ? CODE FOR PLAYING TIC-TOC-TOE GAME IN C++
// ? Name:  Devansh Dubey
// ? University Roll: 2014632
// ? Branch: B.tech(CSE)
// ? Section: D 
// ? Class Roll: 12

// !including the standard c++ library
#include <bits/stdc++.h>
using namespace std;

// !Declaration of game board, p1/p2, r, c, alt
static char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }, ch1;
string p1, p2;
int r, c, alt = 0;

// !function to reset the board values to space once game started
void boardReset() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// !function to print the board whenever updated
void printBoard() {
    system("cls");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0)
                cout << "\t\t\t";
            cout << " " << board[i][j] << " ";
            if (j != 2)
                cout << "|";
        }
        cout << "\n";
        if (i != 2)
            cout << "\t\t\t-----------\n";
    }
}

// !this function is to check if their is a winner everytime the board gets updated
bool isWinner(char ch4) {
    return ((board[0][0] == ch4 && board[0][1] == ch4 && board[0][2] == ch4) ||
        (board[1][0] == ch4 && board[1][1] == ch4 && board[1][2] == ch4) ||
        (board[2][0] == ch4 && board[2][1] == ch4 && board[2][2] == ch4) ||
        (board[0][0] == ch4 && board[1][0] == ch4 && board[2][0] == ch4) ||
        (board[0][1] == ch4 && board[1][1] == ch4 && board[2][1] == ch4) ||
        (board[0][2] == ch4 && board[1][2] == ch4 && board[2][2] == ch4) ||
        (board[0][0] == ch4 && board[1][1] == ch4 && board[2][2] == ch4) ||
        (board[0][2] == ch4 && board[1][1] == ch4 && board[2][0] == ch4));
}

// !this function is check the board is full or not everytime board is updated
bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// !this function is used to update the gameboard
bool makeMove(char c1) {
    if (board[r - 1][c - 1] == ' ') {
        board[r - 1][c - 1] = c1;
        return true;
    }
    else {
        cout << "\nThis Position is Already Occupied!\n\n";
        system("PAUSE");
        return false;
    }
}

// !function to alter the players turns unless the board is full or there is a winner
void playGame()
{
    do {
        if (alt % 2 == 0) {
            cout << "\n\n" << p1 << "'s Turn\n";
            ch1 = 'X';
        }
        else {
            cout << "\n\n" << p2 << "'s Turn\n";
            ch1 = 'O';
        }

        while (1) {
            cout << "Enter Column No. you want to make move: ";
            cin >> c;
            if (c < 1 || c > 3)
                cout << "Enter Coulmn in Range 1 to 3\n";
            else
                break;
        }
        while (1) {
            cout << "Enter Row No. you want to make move: ";
            cin >> r;
            if (r < 1 || r > 3)
                cout << "Enter Row in Range 1 to 3\n";
            else
                break;
        }

        bool res = makeMove(ch1);
        if (res)
            alt++;

        printBoard();
    } while (!isWinner(ch1) && !isBoardFull());
}

// !main function to start the game
int main() {
    char ch;
    system("cls");
    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\tWELCOME TO THE TIC-TAC-TOE GAME\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        cout << "\nEnter First Player's first Name: ";
        cin >> p1;
        cout << "\nEnter Second Player's first Name: ";
        cin >> p2;

        string p11;
        while (p11 != p1 && p11 != p2) {
            cout << "\nWhich player is playing first: ";
            cin >> p11;
            if (p11 != p1 && p11 != p2) {
                cout << p11 << " is not registered!\n";
            }
        }
        if (p1 != p11) {
            alt++;
        }
        cout << "\nSymbol Assigned to " << p1 << " is 'X'\n";
        cout << "Symbol Assigned to " << p2 << " is 'O'\n\n";
        system("PAUSE");

        printBoard();
        playGame();

        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\t\tRESULT: ";
        if (isBoardFull() && !(isWinner('X') || isWinner('O')))
            cout << "Game Tie!\n";
        else if (alt % 2 == 0)
            cout << p2 << " Wins!\n";
        else
            cout << p1 << " Wins!\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "\nDo You Want to Play Again? (Y / N): ";
        boardReset();
        alt = 0;
        cin >> ch;
    } while (ch != 'n' && ch != 'N');
    system("cls");
    cout << "GOOD BYE!\n";
    return 0;
}