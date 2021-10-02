package ConditionAndLoops.ConditionsAndLoops;

import java.util.Scanner;

public class CalculateLCM {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter two no: ");
        long a = in.nextLong();
        long b = in.nextLong();
        long hcf = 1;
        for (int i = 1; i <=a && i<=b ; i++) {
            if(a % i == 0 && b%i == 0){
                hcf = i;
            }
        }
        System.out.println("hcf=" +hcf);
        long lcm = a * b / hcf;
        System.out.println("lcm=" + lcm);
    }
}
