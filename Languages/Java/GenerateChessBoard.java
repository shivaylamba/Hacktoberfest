package Practice.Midterm;

import java.util.Scanner;

public class GenerateChessBoard {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Enter # of Columns & Rows on chess board (Minimum 8): ");
        int size = input.nextInt();

        while(size < 8){
            System.out.println("ERROR: INCORRECT INPUT, MUST BE GREATER OR EQUAL TO 8");
            System.out.print("Enter # of Columns & Rows on chess board (Minimum 8): ");
            size = input.nextInt();

        }

        char[][] chessBoard = new char[size][size];

        fillChessBoard(chessBoard);
        printChessBoard(chessBoard);

    }

    public static void fillChessBoard(char[][] arr) {
        for (int i = 0; i < arr.length; i++)
            for (int j = 0; j < arr.length; j++)
                if ((i + j) % 2 == 0)
                    arr[i][j] = 'x';
    }

    public static void printChessBoard(char[][] arr) {
        int length = arr.length;
        System.out.println("\nSUCCESSFULLY PRINTED OUT A " + length + " X " + length + " CHESSBOARD");
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (arr[i][j] != ' ') {
                    System.out.print(arr[i][j] + "\t");
                } else System.out.print(" " + "\t");
            }
            System.out.println();
        }


    }
}