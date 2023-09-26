// Aggressive Cows : Detailed Solution
// Problem Statement: There is a new barn with N stalls and C cows.
// The stalls are located on a straight line at positions x1,….,xN 
// (0 <= xi <= 1,000,000,000). We want to assign the cows to the stalls, 
// such that the minimum distance between any two of them is as large as 
// possible. What is the largest minimum distance?
// Examples:
// Input: No of stalls = 5 
//        Array: {1,2,8,4,9}
//        And number of cows: 3

// Output: One integer, the largest minimum distance 3



import java.util.*;

class AgressiveCows {
    public static int returnLargestMinimumDistance(int[] arr, int n, int c){
        
        Arrays.sort(arr);
        int low = 1, high = arr[arr.length -1] - arr[0], res = 0;
        while( low <= high){
            int mid = (low + high) >> 1;
            if(isCowPlacementPossible(arr, mid, c)){
                res = Math.max(mid, res);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return res;
    }

    public static boolean isCowPlacementPossible(int[] arr, int dist, int cows){
        int cowPlaced = arr[0], count = 1;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] - cowPlaced >= dist){
                count++;
                cowPlaced = arr[i];
            }
            if(count == cows) return true; 
        }
        return false;   
    }
    
    public static void main(String[] args){
        int[] arr =  { 1, 2, 8, 4 , 9};
        int n = 5, c = 3;
        System.out.println(returnLargestMinimumDistance(arr, n, c));

    }
}