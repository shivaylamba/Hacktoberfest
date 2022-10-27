public class LinearSearch {
   
    public static int linearSearch(int arr[], int x) {
        //Your code goes here
        int n = arr.length;
        int index = -1;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
               index=i;
               break;
            }
        }
        return index;
    }
     //main code to check the program
     public static void main(String[] args) {
        int arr[] = {1, 2,3, 4};
        System.out.println(linearSearch(arr, 5)); //outputs 3 the solution code is ok
    } 
}
