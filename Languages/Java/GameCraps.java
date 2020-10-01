package Java;
/* A Game Of Chance is a dice Game known as craps, which is played in casinos and back
 alleys throughout the world. The rules of the Game are straightforward:

 ==>You roll two dice. Each die has six faces, which contain one, two, three, four, five and
 six spots, respectively. After the dice have come to rest, the sum of the spots on the two
 upward faces is calculated. If the sum is 7 or 11 on the first throw, you win. If the sum
 is 2, 3 or 12 on the first throw (called “craps”), you lose (i.e., the “house” wins). If the
 sum is 4, 5, 6, 8, 9 or 10 on the first throw, that sum becomes your “point.” To win,
 you must continue rolling the dice until you “make your point” (i.e., roll that same
 point value). You lose by rolling a 7 before making your point. */

import java.util.Random;

public class GameCraps {
    //create random number generator for use in method RollDice
    private static final Random randomNumbers = new Random();

    //constants that represents common rolls of the dice
    private static final int SNAKE_EYES = 2;
    private static final int TREY = 3;
    private static final int SEVEN = 7;
    private static final int YO_ELEVEN = 11;
    private static final int BOX_CARS = 12;

    //roll dice calculates and displays results
    private static int RollDice() {
        //generates random die values
        int die1 = 1 + randomNumbers.nextInt(6);
        int die2 = 1 + randomNumbers.nextInt(6);
        int sum = die1 + die2;
        System.out.printf("Player rolled %d + %d = %d\n", die1, die2, sum);
        return sum;
    }

    //method main begins program execution
    public static void main(String[] args) {
        int myPoint = 0; //when no win or loss value is rolled
        int sumOfDice = RollDice();
        Status gameStatus; //to check for WON, CONTINUE or LOST

        //determine the GameYahtzee status on first roll
        switch (sumOfDice) {
            case SEVEN: //win with seven on first roll
            case YO_ELEVEN: //win with eleven on first roll
                gameStatus = Status.WON;
                break;
            case SNAKE_EYES: //lose with 2 on first roll
            case TREY: //lose with 3 on first roll
            case BOX_CARS: //lose with 12 on first roll
                gameStatus = Status.LOST;
                break;
            default: //did not win or lose, so remember point
                gameStatus = Status.CONTINUE;
                myPoint = sumOfDice;
                System.out.print("Point is: " + myPoint);
                System.out.println();
        }

        while (gameStatus == Status.CONTINUE) {
            sumOfDice = RollDice();

            //win by making point
            if (sumOfDice == myPoint)
                gameStatus = Status.WON;

                //lose by rolling 7 before making point
            else if (sumOfDice == SEVEN) {
                gameStatus = Status.LOST;
            }
        }

        //tell if player wins or lost
        if (gameStatus == Status.WON) {
            System.out.println("Player wins");
        } else System.out.println("Player loses");

    }

    //enumerations with constants that represents the GameYahtzee status
    private enum Status {WON, CONTINUE, LOST}

}
