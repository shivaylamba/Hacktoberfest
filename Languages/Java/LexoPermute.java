package com.sonal;

import java.util.Scanner;

public class LexoPermute {
    public static int[] freq(String s){

        //frequency array to count the no of times a character is appearing
        int ar[] = new int[26];

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            ar[ch-'a']++;
        }
        return ar;
    }

    public static void permutelexo(String pro, int freq[], int length){

        if(length==0){
            System.out.println(pro);
            return;
        }

        for (int i = 0; i < freq.length; i++) {

            if(freq[i]>0){
                //for printing characters
                freq[i]--;
                permutelexo(pro + (char)(i+'a'), freq, length-1);
                //back tracking
                freq[i]++;
            }
        }
    }
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        String string = s.next();
        int freq[]=freq(string);
        permutelexo("", freq, string.length());
    }
}
