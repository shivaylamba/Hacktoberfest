import java.util.Scanner;
public class FindGreatestNumber {
    int num1,num2,num3,large;
    public void setvalue(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first number:");
        num1 = sc.nextInt();
        System.out.print("Enter the second number:");
        num2 = sc.nextInt();
        System.out.print("Enter the third number:");
        num3 = sc.nextInt();
        sc.close();
    }
    public void calcGreatest(){
        large=num1>num2?(num1>num3?num1:num3):(num2>num3?num2:num3);
        System.out.println("Greatest number is:"+num3);
        }
    }
    public static void main(String[] args) {
        System.out.println("Program to Find Greatest Number");
        FindGreatestNumber g = new FindGreatestNumber();
        g.setvalue();
        g.calcGreatest();
    }

}
