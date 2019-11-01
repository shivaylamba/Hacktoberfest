
import java.util.*;

class DeleteElements {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        System.out.println("Enter the array elements");
        int a[]= new int[n];

        for(int i = 0; i < n; i++)
        {
            a[i] = sc.nextInt();
        }

        System.out.println("Insert the index you want to delete: ");
        int delete_index = sc.nextInt();

        for (int i = delete_index; i < n - 1; i++) 
            a[i] = a[i + 1];

        System.out.println("Array after deletion");
        for(int i = 0; i < n - 1; i++)
        {
            System.out.println(a[i]);
        }

    }

}
