package com.company.basic;

import java.util.*;

public class Prac2 {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int sumeven=0;
		int sumodd=0;
		String str=scan.next();
		char arr[]=new char[str.length()];
		for(int i=0;i<str.length();i++) {
			arr[i]=str.charAt(i);
		}
		for(int j=0;j<str.length();j++) {
			if(j%2==0) {
				sumeven+=Character.getNumericValue(str.charAt(j));
			}else {
				sumodd+=Character.getNumericValue(str.charAt(j));
			}
		}
		System.out.println(Arrays.toString(arr));
		System.out.println(sumeven);
		System.out.println(sumodd);
}}
