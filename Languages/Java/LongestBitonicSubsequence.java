/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    
    public static int LBS(int[]arr){
        
        int[] lis = new int[arr.length];
        
        lis[0] = 1;
        for(int i = 1; i < arr.length; i++){
            for(int j = 0; j<i; j++){
                if(arr[j]<arr[i]){
                    lis[i] = Math.max(lis[j],lis[i]);
                }
            }
            lis[i]++;
        }
        
        int[] lds = new int[arr.length];
        lds[arr.length-1] = 1;
        
        for(int i = arr.length-2; i>=0; i--){
            for(int j = arr.length-1 ; j>i ; j--){
                if(arr[j]<arr[i]){
                    lds[i] = Math.max(lds[j],lds[i]);
                }
            }
            lds[i]++;
        }
        
        int lbsl = Integer.MIN_VALUE; //LBS lenght
        
        for(int i = 0; i < arr.length; i++){
            if(lis[i] + lds[i] -1 > lbsl){
                lbsl = lis[i] + lds[i] - 1;//***
            }
        }
        
        return lbsl;
    }
    
    
	public static void main (String[] args) {
		//code
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while(t-->0){
		    int n = scn.nextInt();
		    int[] arr = new int[n];
		    for(int i = 0; i < n;i++){
		        arr[i] = scn.nextInt();
		    }
		    System.out.println(LBS(arr));
		}
	}
}
