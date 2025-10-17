import java.util.Random;
import java.util.Scanner;

public class NumberGuesser {

    public static void main(String[] args) {
        // 1. Initialize necessary objects and variables.
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);
        
        int minRange = 1;
        int maxRange = 100;
        // Generate a secret number between 1 and 100 (inclusive).
        int secretNumber = random.nextInt(maxRange - minRange + 1) + minRange; 
        
        int userGuess = 0;
        int attempts = 0;

        System.out.println("🎉 Welcome to the Number Guessing Game! 🎉");
        System.out.println("I've picked a number between " + minRange + " and " + maxRange + ". Try to guess it!");
        System.out.println("----------------------------------------------");

        // 2. Start the main game loop.
        while (userGuess != secretNumber) {
            System.out.print("Enter your guess: ");
            
            try {
                userGuess = Integer.parseInt(scanner.nextLine());
                attempts++; // Increment attempts after a valid guess.

                // 3. Provide feedback to the user.
                if (userGuess < secretNumber) {
                    System.out.println("Too low! Try again.");
                } else if (userGuess > secretNumber) {
                    System.out.println("Too high! Try again.");
                } else {
                    // 4. Congratulate the user on the correct guess.
                    System.out.println("\n🎉 Correct! You guessed the number!");
                    System.out.println("The secret number was: " + secretNumber);
                    System.out.println("It took you " + attempts + " attempts.");
                }
            } catch (NumberFormatException e) {
                // Handle cases where input is not a valid number.
                System.out.println("Invalid input. Please enter a whole number.");
            }
        }
        
        // 5. Close the scanner to prevent resource leaks.
        scanner.close();
    }
}