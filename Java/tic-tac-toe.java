import java.util.Scanner;

public class TicTacToe {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[][] board = new char[3][3];
        char currentPlayer = 'X';

        initializeBoard(board);

        boolean gameWon = false;
        int moves = 0;

        while (!gameWon && moves < 9) {
            printBoard(board);
            System.out.println("Player " + currentPlayer + ", enter your move (row and column):");
            
            int row = scanner.nextInt();
            int col = scanner.nextInt();
            
            if (isValidMove(board, row, col)) {
                board[row][col] = currentPlayer;
                moves++;
                
                if (checkWin(board, currentPlayer)) {
                    gameWon = true;
                    printBoard(board);
                    System.out.println("Player " + currentPlayer + " wins!");
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                System.out.println("Invalid move. Try again.");
            }
        }
        
        if (!gameWon) {
            printBoard(board);
            System.out.println("It's a draw!");
        }
        
        scanner.close();
    }

    private static void initializeBoard(char[][] board) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    private static void printBoard(char[][] board) {
        System.out.println("-------------");
        for (int i = 0; i < 3; i++) {
            System.out.print("| ");
            for (int j = 0; j < 3; j++) {
                System.out.print(board[i][j] + " | ");
            }
            System.out.println("\n-------------");
        }
    }

    private static boolean isValidMove(char[][] board, int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    private static boolean checkWin(char[][] board, char player) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true; // Horizontal win
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true; // Vertical win
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true; // Diagonal win (top-left to bottom-right)
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true; // Diagonal win (top-right to bottom-left)
        }
        return false;
    }
}
