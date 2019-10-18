package com.company.Lec4;

import java.util.Scanner;

public class Binary2deci {
    public static void main(String[] args) {
        int n=1011;
        //  int a=bin2deci(n);
        System.out.println(bin2deci(n));
        int c=deci2bin(11);
        System.out.println(c);
        System.out.println(inverse(1342));
    }

    public static int bin2deci(int bin){

        int deci=0;
        int place=1;

        while(bin>0){

            int rem=bin%10;
            bin=bin/10;
            deci=deci+rem*place;
            place=place*2;
        }

        return deci;
    }

    public static int any2deci(int any ,int base){

        int deci=0;
        int place=1;

        while(any>0){

            int rem=any%10;
            any=any/10;
            deci=deci+rem*place;
            place=place*base;
        }

        return deci;
    }

    public static int deci2bin(int deci){

        int bin=0;
        int place=1;

        while(deci>0){

            int rem=deci%2;
            deci=deci/2;
            bin=bin+rem*place;
            place=place*10;
        }

        return bin;
    }

    public static int deci2any(int deci,int base){

        int any=0;
        int place=1;

        while(deci>0){

            int rem=deci%base;
            deci=deci/base;
            any=any+rem*place;
            place=place*10;
        }

        return any;
    }

    public static int any2any(int any,int fbase ,int sbase) {

        int deci=any2deci(any,fbase);
        return deci2any(deci,sbase);
    }

    public static int inverse(int n){

        int in=0;
        int place=1;

        while(n>0){

            int value=n%10;
            n=n/10;
            in = (int) (in +place*Math.pow(10,value-1));
            place=place+1;
        }
        return  in;
    }


}
