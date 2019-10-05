package LAB4;

import java.util.Scanner;

class AgeException extends Exception{
    AgeException(String s){
        super(s);
    }
}

class TooYoungException {
    static void check(int age1){
        try{
            if(age1<18)
                throw new AgeException("You are too young to vote.");
            else
                System.out.println("You can vote.");
        }catch (Exception e){
            System.out.println(e);
        }
    }
}

class InvalidAgeException {
    static  void validate(int age){
        try{
            if(age<0) {
                throw new AgeException("Age not valid.");
            }
            else
                System.out.println("\nEntered age is valid.");
        }catch (Exception e){
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter your age to verify :- ");
        int x = scan.nextInt();
        InvalidAgeException.validate(x);
        TooYoungException.check(x);
    }
}
