import java.util.*;

public class TextAnalyzer {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a text to analyze:");
        String text = sc.nextLine();

        // Word count
        String[] words = text.split("\\s+");
        int wordCount = words.length;

        // Sentence count
        String[] sentences = text.split("[.!?]");
        int sentenceCount = sentences.length;

        // Average word length
        int totalLength = 0;
        for (String w : words) totalLength += w.length();
        double avgWordLength = (double) totalLength / wordCount;

        // Most frequent word
        Map<String, Integer> freq = new HashMap<>();
        for (String w : words) {
            w = w.toLowerCase().replaceAll("[^a-z]", "");
            if (w.isEmpty()) continue;
            freq.put(w, freq.getOrDefault(w, 0) + 1);
        }
        String mostFreq = Collections.max(freq.entrySet(), Map.Entry.comparingByValue()).getKey();

        System.out.println("\n--- Text Analysis ---");
        System.out.println("Word count: " + wordCount);
        System.out.println("Sentence count: " + sentenceCount);
        System.out.println("Average word length: " + String.format("%.2f", avgWordLength));
        System.out.println("Most frequent word: " + mostFreq);
    }
}
