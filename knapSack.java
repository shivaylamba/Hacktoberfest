import java.util.*;
public class knapSack {
    static class Item {
        int weight, value;
        Item(int weight, int value) {
            this.weight = weight;
            this.value = value;
        }
    }
    static int knapsack01(Item[] items, int W) {
        int n = items.length;
        int[][] dp = new int[n + 1][W + 1];
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (items[i - 1].weight <= w) {
                    dp[i][w] = Math.max(
                        items[i - 1].value + dp[i - 1][w - items[i - 1].weight],
                        dp[i - 1][w]
                    );
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
    static double fractionalKnapsack(Item[] items, int W) {
        Arrays.sort(items, (a, b) -> Double.compare((double)b.value / b.weight, (double)a.value / a.weight));
        double totalValue = 0.0;
        int currentWeight = 0;
        for(Item item : items) {
            if(currentWeight + item.weight <= W) {
                currentWeight += item.weight;
                totalValue += item.value;
            } 
            else {
                int remain = W - currentWeight;
                totalValue += (item.value * ((double) remain / item.weight));
                break;
            }
        }
        return totalValue;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Select Knapsack Type: ");
        System.out.println("1. Fractional Knapsack");
        System.out.println("2. 0/1 Knapsack");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = sc.nextInt();
        System.out.print("Enter number of items: ");
        int n = sc.nextInt();
        Item[] items = new Item[n];
        for(int i = 0; i < n; i++) {
            System.out.print("Enter weight and value for item " + (i + 1) + ": ");
            int w = sc.nextInt();
            int v = sc.nextInt();
            items[i] = new Item(w, v);
        }
        System.out.print("Enter knapsack capacity: ");
        int W = sc.nextInt();
        switch(choice) {
            case 1:
                double maxValFractional = fractionalKnapsack(items, W);
                System.out.println("\nMaximum value in Fractional Knapsack = " + maxValFractional);
                break;

            case 2:
                int maxVal01 = knapsack01(items, W);
                System.out.println("\nMaximum value in 0/1 Knapsack = " + maxVal01);
                break;

            default:
                System.out.println("Invalid choice! Please enter 1 or 2.");
        }
        sc.close();
    }
}
