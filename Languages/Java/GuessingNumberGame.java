package Java;

import java.util.Scanner;

public class GuessingNumberGame {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        //generates pseudo-random number from 1 to 1000
        int randomNumber = 1 + (int) (Math.random() * 1000);
        System.out.print("Guess a number between 1 and 1000: ");
        int guess = input.nextInt(); //reads an integer input from user
        int count = 1; //keeps track of the number of guess(es)
        while (guess != randomNumber) {
            if (guess > randomNumber) {
                System.out.println("INCORRECT!! " + guess + " is too high. Try again");
            } else {
                System.out.println("INCORRECT!! " + guess + " is too low. Try again");
            }
            System.out.print("Guess again: ");
            guess = input.nextInt();
            count++;
        }
        //checking the number of times the user guessed
        if (count < 10) {
            System.out.println("Either you know the secret! or you got lucky");
        } else if (count > 10) {
            System.out.println("You should be able to do better");
        } else {
            System.out.println("Aha! you know the secret!");
        }
        System.out.println("CONGRATULATIONS, the guess number is " + guess);
    }
}
