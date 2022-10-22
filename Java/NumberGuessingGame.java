import java.util.Scanner;

public class NumberGuessingGame {
   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int myNumber = (int)(Math.random()*100);
       int k;
       System.out.println("Starting the game in few Seconds ");
       try{
       Thread.sleep(2500);
       }catch(InterruptedException ex)
      {
          ex.printStackTrace();
      }
       int userNumber = 0;

       do {
           System.out.println("Guess my number(1-100) : ");
           userNumber = sc.nextInt();

           if(userNumber == myNumber) {
               System.out.println("WELL DONE.. CORRECT NUMBER!!!");
               break;
           }
           else if(userNumber > myNumber) {
               System.out.println("your number is too large");
               System.out.println("Do you Still want to play enter 1 else 0");
               k=sc.nextInt();
               if(k==1){
                   continue;
               }
               if(k==0){
                   
                   break;
               }
               else{
                   System.out.println("You have chosen Wrong choise so we are closing the game ");
                   break;
               }
               
           }
           else {
               System.out.println("your number is too small");
               System.out.println("Do you Still want to play enter 1 else 0");
                k=sc.nextInt();
               if(k==1){
                   continue;
               }
               if(k==0){
                   
                   break;
               }
               else{
                   System.out.println("You have chosen Wrong choise so we are closing the game ");
                   break;
               }
           }
       } while(userNumber >= 0);
      System.out.println("Thank You For Playing with us..");
       System.out.print("My number was : ");
       System.out.println(myNumber);
   }
}
