public class ArraySum {

    static int arr[] = { 11, 2, 3, 4, 8 };

    static int Sum(int A[], int n) {
        
        if (n <= 0)
            return 0;
        return (Sum(A, n - 1) + A[n - 1]);
    }

    public static void main(String[] args){
      
        System.out.println("The sum of elements of the array is: "+ Sum(arr, arr.length));
    }
}