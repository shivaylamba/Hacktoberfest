/*This will find that the given array is sorted or not. if sorted it'll 
return true else return false.
This is done using recursion.
*/

public class FindArraySortedOrNot {
public static void main(String[] args) {
   int arr[]={1,3,5,9,7,8};
    System.out.println(Sorted(arr,5));
}
//method to find array sorted or not
public static boolean Sorted(int[] arr,int n){
    if(n==0){
        return true;
    }
    
    boolean sort1=Sorted(arr,n-1);
    if(sort1==false){
        return false;
    }
    else{
        if(arr[n-1]<arr[n]){
            return true;
        }
        else{
            return false;
        }
    }
}
}
