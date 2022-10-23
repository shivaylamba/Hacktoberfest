// java program to reverse a word

import java.io.*;
import java.util.Scanner;

class ReverseString {
	public static void main (String[] args) {
		Scanner sc= new Scanner(System.in);
		
		System.out.println("Entern String");
		String str=sc.nextLine();
		String nstr="";
		char ch;
		
	System.out.print("Original word: ");
	System.out.println(str); //Example word
		
	for (int i=0; i<str.length(); i++)
	{
		ch= str.charAt(i); //extracts each character
		nstr= ch+nstr; //adds each character in front of the existing string
	}
	System.out.println("Reversed word: "+ nstr);
	}
}

//Contributed by Tiyasa
