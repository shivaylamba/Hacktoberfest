package com.sonal;

import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {

        Scanner s= new Scanner(System.in);
        int num= s.nextInt();
        int remainder=0, rev=0, count=0;

        while(num>0){

            remainder=num%10;

            if(remainder == 0){
                count++;
            }

            num=num/10;
            rev=rev*10 + remainder;
        }
        if(count!=0){
            while(count>0){
                System.out.print(0);
                count--;
            }
        }
        System.out.println(rev);

    }
}
