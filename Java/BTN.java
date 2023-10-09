himport java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class RandomNumberGenerator {
    public static void main(String[] args) {
        // Initialize a random number generator
        Random random = new Random();

        // Generate a list of random numbers
        List<Integer> randomNumbers = new ArrayList<>();
        int numSamples = 10; // Number of random numbers to generate

        for (int i = 0; i < numSamples; i++) {
            int randomNumber = random.nextInt(100) + 1; // Generates a random number between 1 and 100
            randomNumbers.add(randomNumber);
        }

        // Calculate the average of the generated random numbers
        int sum = 0;
        for (int num : randomNumbers) {
            sum += num;
        }
        double average = (double) sum / numSamples;

        // Print the random numbers and their average
        System.out.print("Random Numbers: ");
        for (int num : randomNumbers) {
            System.out.print(num + " ");
        }
        System.out.println("\nAverage: " + average);
    }
}
