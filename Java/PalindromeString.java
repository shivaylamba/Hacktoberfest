import java.util.Scanner;

public PalindromeString {
    public static void main(String[] args) {
        //To find out whether the given String is Palindrome or not.
        //-------------------------------
        System.out.print("Enter a string: ");
        Scanner stringIp = new Scanner(System.in);
        String string = stringIp.next();

        int start = 0;
        int end = string.length() - 1;
        boolean isPalindrome = true;
        while (start < end) {
            if(string.charAt(start) != string.charAt(end)) {
                isPalindrome = false;
                break;
            }
            start++;
            end--;
        }
        if(isPalindrome) {
            System.out.println("Palindrome");
        } else {
            System.out.println("Not a Palindrome");
        }
    }
}
