import java.util.*;

public class q4 {
    //by o(n^2) algo
    static int maximum_sub_array_2(int arr[])
    {
        int l,k;
        int csum_2=0;
        int osum_2=0;
        for(k=0;k<arr.length;k++)
        {
            for(l=k;l<arr.length;l++)
            {
                if (csum_2>=0)
                {
                    csum_2=csum_2+arr[l];
                }
                else
                {
                    csum_2=arr[l];
                }
                if(csum_2>osum_2)
                {
                    osum_2=csum_2;
                }
            }
            return osum_2;
        }
        return -1;
    }
    //by o(n) algorithm
    static int maximum_sub_array_1(int arr[]) {
        int csum = arr[0];
        int osum = arr[0];
        int i = 0;
        for (i = 1; i < arr.length; i++) {
            if (csum >= 0) {
                csum = csum + arr[i];
            } else {
                csum = arr[i];
            }
            if (osum < csum) {
                osum = csum;
            }
        }
        return osum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int j=0;
        int n=0;
        System.out.println("Enter the value of n");
        n=sc.nextInt();
        int arr[] = new int[n];
        for (j = 0; j < n; j++) {
            arr[j] = sc.nextInt();
        }
        System.out.println(maximum_sub_array_1(arr));
        System.out.println(maximum_sub_array_2(arr));
    }
}
