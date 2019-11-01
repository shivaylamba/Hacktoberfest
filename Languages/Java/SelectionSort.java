

import java.util.*;
class SelectionSort {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        System.out.println("Enter the array elements");
        int a[]= new int[n];
        int flag= 0;

        for(int i = 0; i < n; i++)
        {
            a[i] = sc.nextInt();
        }

        for(int i=0; i<n-1; i++)
        {
            int min=i;
            for(int j=i+1; j<n; j++)
            {
                if(a[j]<a[min])
                {
                    min=j;
                }
            }
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;        

        }
        System.out.println("sorted array:");
        for(int i = 0; i < n; i++)
        {
            System.out.println(a[i]);

        }

    }
}