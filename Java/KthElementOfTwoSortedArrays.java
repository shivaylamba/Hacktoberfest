//KthElementOfTwoSortedArrays

//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            StringTokenizer stt = new StringTokenizer(br.readLine());
            
            int n = Integer.parseInt(stt.nextToken());
            int m = Integer.parseInt(stt.nextToken());
            int k = Integer.parseInt(stt.nextToken());
            int a[] = new int[(int)(n)];
            int b[] = new int[(int)(m)];
            
            
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }
            String inputLine1[] = br.readLine().trim().split(" ");
            for (int i = 0; i < m; i++) {
                b[i] = Integer.parseInt(inputLine1[i]);
            }
            
            
            Solution obj = new Solution();
            System.out.println(obj.kthElement( a, b, n, m, k));
            
        }
	}
}

// } Driver Code Ends


//User function Template for Java


class Solution {
    public long kthElement( int arr1[], int arr2[], int n, int m, int k) {
        // int p1=0,p2=0,counter=0,answer=0;
        
        // while(p1<m && p2<n) {
        //     if(counter == k) break;
        //     else if(array1[p1]<array2[p2]) {
        //         answer = array1[p1];
        //         ++p1;
        //     }
        //     else {
        //         answer = array2[p2];
        //         ++p2;
        //     }
        //     ++counter;
        // }
        // if(counter != k) {
        //     if(p1 != m-1) 
        //         answer = array1[k-counter];
        //     else 
        //         answer = array2[k-counter];
        // }
        // return answer;
        
        if(m > n){
            kthElement( arr2, arr1, m, n, k); 
        }
        
        int low = Math.max(0,k-m) , high = Math.min(k,n);
        
        while(low <= high){
            
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0? Integer.MIN_VALUE : arr1[cut1-1];
            int l2 = cut2 == 0? Integer.MIN_VALUE : arr2[cut2-1];
            
            int r1 = cut1 == n? Integer.MAX_VALUE : arr1[cut1];
            int r2 = cut2 == m? Integer.MAX_VALUE : arr2[cut2];
            
            if( l1 <= r2 && l2 <= r1){
                return Math.max(l1,l2);
            }
            else if(l1 > r2){
                high = cut1 -1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return -1;
    }
}