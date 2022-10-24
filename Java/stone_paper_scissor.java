import java.util.Scanner;
import java.util.Random;

public class stonepaperscissor 
{
	public static void main(String[] args)
	{
		 String name;
		 int userinput,no;
		 System.out.println("Hello And Welcome To The Game ");
		 System.out.println("ROCK | PAPER  | SCISSOR ");
		 Scanner va = new Scanner(System.in);

		 System.out.println("Enter Your Good Name ");
		 name = va.nextLine();
		 
		 System.out.println("Enter The Rounds You Want to Play ");
		 no  = va.nextInt();
		 
		 System.out.println("So Hi "+name+", So In this game Your Opponent is COMPUTER ");
		 System.out.println("So Lets Begin......:)");
		for(int i = 1;i<=no;i++)
		{
		 System.out.println(" 0 For Rock ");
		 System.out.println(" 1 For Paper ");
		 System.out.println(" 2 For Scissor ");
		 System.out.println("Enter Your Option ");
		 userinput = va.nextInt();
		 
		 Random random = new Random();
		 int computerinput = random.nextInt(2);
		 
		 if(userinput == computerinput)
		 {
			 System.out.println("The Match is Draw");
			 System.out.println("Your Move was : "+userinput);
			 System.out.println("Computer's Move was : "+computerinput);
			 System.out.println(userinput+" = "+computerinput);
		 }
		 else if(userinput == 0 && computerinput == 2 || userinput == 1 && computerinput == 0 || userinput == 2 && computerinput == 1 )
		 {
			 System.out.println("Your Move was : "+userinput);
			 System.out.println("Computer's Move was : "+computerinput);
			 System.out.println("******Congragulation****");
			 System.out.println(name+" You have Won The Match");
		 }
		 else
		 {
			 System.out.println("Your Move was : "+userinput);
			 System.out.println("Computer's Move was : "+computerinput);
			 System.out.println("..Computer Wins..");
		 }
		}
	}

	}

