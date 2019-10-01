package LAB4;

import java.util.Scanner;

public class multipleCatch {
    public static void main(String[] args) {
        int[] a = new int[5];
        int b=0;
        int c;
        try{
            Scanner s=new Scanner(System.in);
            System.out.println("enter value of A : ");
            a[0] = s.nextInt();
            System.out.println("Enter value of B : ");
            b = s.nextInt();
            System.out.println("Answer : " + a[6]/b);
        }
        catch(ArithmeticException e){
            System.out.println(e);
        }
        catch(ArrayIndexOutOfBoundsException e1){
            System.out.println(e1);
        }
    }
}
