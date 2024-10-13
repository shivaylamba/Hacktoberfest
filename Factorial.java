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

    //Using Recursion (2nd Approach)
    public static int factorialOfNum(int num) {
        //base case
        if(num == 0) {
            return 1;
        }
        int fnm1 = factorialOfNum(num-1);
        int fn = num * fnm1;
        return fn;
    }

    public static void main(String[] args) {
        Factorial Fact = new Factorial();
        System.out.print("Enter a Number: ");
        Fact.set_data();
        Fact.fact();
        
        //2nd Approach (Output) Call the function and pass the number in it
        System.out.println("The Factorial of the number is : "+ factorialOfNum(4));
    }
}
