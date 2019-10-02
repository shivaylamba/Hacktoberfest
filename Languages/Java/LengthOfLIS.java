//Length Of Longest increasing substring using DP Optimal Substructure problem

package DynamicProgramming;
import java.util.*;

public class LengthOfLongestIncreasingSub {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int arr[] = {10 , 22 , 9 , 33 , 21 , 50 , 41 ,60};
		
		int l = calLengthofLIS(arr);
		
		System.out.println(l);

	}
	
	public static int calLengthofLIS(int[] arr){
		
		//DP will be storing the max length until ith element of arr
		int dp[] = new int[arr.length];
		
		Arrays.fill(dp,1);
		
		for (int i = 1; i < dp.length; i++) {
			for (int j = 0; j < i; j++) {
				if(arr[i]>arr[j]){
					dp[i] = Math.max(dp[j]+1 , dp[i]);
				}
			}
		}
		
		return dp[arr.length-1];
	}

}
