import java.util.Scanner;
import java.util.Random;
public class Rock_Paper_Scissor {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int com = random.nextInt(3);
        String computer = null;
        if(com==0){
            computer = "rock";
        }
        else if(com==1){
            computer = "paper";
        }
        else if(com==2){
            computer = "scissor";
        }
        System.out.print("Enter your move: ");
        String user = sc.next();
        String player = user.toLowerCase();
        System.out.println("Your move: " + player);
        System.out.println("Computer's move: " + computer);

        if (player.equals("rock") && computer.equals("rock")){
            System.out.println("Tie");
        }
        else if (player.equals("paper") && computer.equals("paper")){
            System.out.println("Tie");
        }
        else if (player.equals("scissor") && computer.equals("scissor")){
            System.out.println("Tie");
        }
        else if (player.equals("paper") && computer.equals("rock")){
            System.out.println("Player wins");
        }
        else if (player.equals("scissor") && computer.equals("rock")){
            System.out.println("Computer wins");
        }
        else if (player.equals("rock") && computer.equals("paper")){
            System.out.println("Computer wins");
        }
        else if (player.equals("rock") && computer.equals("scissor")){
            System.out.println("Player wins");
        }
        else if (player.equals("paper") && computer.equals("scissor")){
            System.out.println("Computer wins");
        }
        else if (player.equals("scissor") && computer.equals("paper")){
            System.out.println("Player wins");
        }
        else{
            System.out.println("Please try again");
        }

    }
}
