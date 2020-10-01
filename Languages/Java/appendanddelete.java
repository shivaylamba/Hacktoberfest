package hackerrank_medium;

import java.util.Scanner;

public class appendanddelete {
    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        String s=scn.next();
        String t=scn.next();
        int k=scn.nextInt();


        int commonLength = 0;

        for (int i=0; i<Math.min(s.length(),t.length());i++){
            if (s.charAt(i)==t.charAt(i))
                commonLength++;
            else
                break;
        }
//CASE A
        if((s.length()+t.length()-2*commonLength)>k){
            System.out.println("No");
        }
//CASE B
        else if((s.length()+t.length()-2*commonLength)%2==k%2){
            System.out.println("Yes");
        }
//CASE C
        else if((s.length()+t.length()-k)<0){
            System.out.println("Yes");
        }
//CASE D
        else{
            System.out.println("No");
        }
    }

}
