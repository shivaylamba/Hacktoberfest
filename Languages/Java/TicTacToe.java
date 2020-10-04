import java.util.Scanner;

class Main{
	public static final Scanner scan = new Scanner(System.in);
	public static char [][] board = new char [3][3];
	public static int row,col;
	public static char turn = 'X';
	public static int count = 0;
	public static void main(String [] args)
	{
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				board[i][j] = '_';
			}
		}
		printBoard();
		play();
	}
	public static void play()
	{
		boolean playing = true;
		while(playing)
		{
			count++;
			System.out.print("\nPlayer "+turn+" Enter your row and column:");
			row = scan.nextInt()-1;
			col = scan.nextInt()-1;
			board[row][col] = turn;
			if(gameOver(row,col))
			{
				System.out.println("Game over! Player "+turn+" wins!!\n\nCode By Bhaveshgoyal182");
				System.exit(0);
			}
			if(count==9)
				{System.out.println("Match Drawn!!\n\nCode By Bhaveshgoyal182");System.exit(0);}
			if(turn=='X')
				turn = 'O';
			else
				turn = 'X';
			
			printBoard();
		}
	}
	
	public static void printBoard()
	{
		System.out.println();
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(j==0)System.out.print("| ");
				System.out.print(board[i][j]+" | ");
			}System.out.println();
			}
	}
	public static boolean gameOver(int ro,int cl)
	{
		if((board[ro][0]==board[ro][1])&&(board[ro][1]==board[ro][2]))
			return true;
		if((board[0][cl]==board[1][cl])&&(board[1][cl]==board[2][cl]))
			return true;
		if((board[0][0]==board[1][1])&&(board[1][1]==board[2][2]) && board[1][1]!='_')
			return true;
		if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!='_')
			return true;
		return false;
	}
}
//try by bhaveshgoyal182
