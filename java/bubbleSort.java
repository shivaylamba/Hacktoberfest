
import java.util.Scanner;
public class bubbleSort {
    public void bubble(int[] arr,int n){
       for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
       }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the size of array:");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("enter the elements of array:");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        bubbleSort sorter=new bubbleSort();
        sorter.bubble(arr,n);
        for(int j=0;j<n;j++){
           System.out.println(arr[j]);
        }
        sc.close();
    }
}
