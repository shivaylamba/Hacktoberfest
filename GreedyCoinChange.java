import java.util.Arrays;

public class GreedyCoinChange {
    public static void main(String[] args) {
        int[] coins = {25, 10, 5, 1}; // Coin denominations in cents
        int amount = 63; // Amount for which we want to make change

        int[] change = makeChange(coins, amount);

        System.out.println("Minimum number of coins needed: " + change[0]);
        System.out.println("Coins used:");

        for (int i = 1; i < change.length; i++) {
            if (change[i] > 0) {
                System.out.println(coins[i - 1] + " cents: " + change[i]);
            }
        }
    }

    public static int[] makeChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int[] change = new int[coins.length + 1];
        int remainingAmount = amount;

        for (int i = coins.length - 1; i >= 0; i--) {
            int coinValue = coins[i];
            int numCoins = remainingAmount / coinValue;
            change[i + 1] = numCoins;
            remainingAmount -= numCoins * coinValue;
        }

        change[0] = amount - remainingAmount;
        return change;
    }
}
