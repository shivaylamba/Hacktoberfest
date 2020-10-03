import java.util.*;

public class program04 {

    public static void main(String args[]) {
        // TODO code application logic here
        Scanner ip = new Scanner(System.in);
        System.out.print("Enter a positive number: ");
        long num = ip.nextLong();
        String s;
        s = "" + num;
        int i,n = s.length();
        boolean result = true;
        for(i=0;i<(n/2);i++){
            if(s.charAt(i) != s.charAt(n-i-1)){
                result = false;
                break;
            }
        }
        if(result){
            System.out.println("The positive number " + num + " is a palindrome.");
        }else{
            System.out.println("The positive number " + num + " is not a palindrome.");
        }
    }
}
