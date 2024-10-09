import java.util.Scanner;//reverse
public class reverse {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n,digit,rev=0;
        System.out.println("enter the no: ");
        n=input.nextInt();
        while(n!=0){
            digit=n%10;
            rev=rev*10+digit;
            n=n/10;
        }
        System.out.println("reverse of a number is:"+rev);
        input.close();
    }
}
