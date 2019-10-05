package javaprograms;

import java.util.Scanner;

public class binarysearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner S=new Scanner(System.in);
		int n=S.nextInt();
        int arr[] = new int[n]; 
        for(int i=0;i<n;i++) {
        	arr[i]=S.nextInt();
        }
        int x = S.nextInt();
        int result = binarySearch(arr, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at "
                               + "index " + result);
	}
	static int binarySearch(int arr[], int x) 
    { 
        int l = 0, r = arr.length - 1; 
        while (l <= r) { 
            int m = l + (r - l) / 2; 
  
            if (arr[m] == x) 
                return m; 
  
            if (arr[m] < x) 
                l = m + 1; 
  
            else
                r = m - 1; 
        } 
  
 
        return -1; 
    } 

}
