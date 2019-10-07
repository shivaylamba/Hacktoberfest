public enum Palindrome {
    INSTANCE;

    public boolean isPalindrome(String input) {
        return new StringBuilder(input).reverse().toString().equalsIgnoreCase(input);
    }
}