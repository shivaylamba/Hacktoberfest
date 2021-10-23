import java.util.Scanner;
public class Factorial {
    int number;
    public void set_data(){
        Scanner sc = new Scanner(System.in);
        number=sc.nextInt();
        sc.close();
    }
    public void fact(){
        int fact =1;
        for(int i=2;i<=number;i++)
            fact=fact*i;
        System.out.println("Factorial is: "+fact);
    }
    public static void main(String[] args) {
        Factorial Fact = new Factorial();
        System.out.print("Enter a Number: ");
        Fact.set_data();
        Fact.fact();
    }
}
