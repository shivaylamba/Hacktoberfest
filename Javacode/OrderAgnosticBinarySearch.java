import java.util.Scanner;

public class OrderAgnosticBinarySearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n=sc.nextInt();
        int[] array = new int[n];
        for(int i=0;i<n;i++)
        {
            array[i]=sc.nextInt();
        }
        int target;
        target = sc.nextInt();
        if(array[0]>array[n-1])
        {
            descendingBinarysearch(array,target);
        }
        else {
            ascendingBinarysearch(array, target);
        }
    }

    public static void ascendingBinarysearch(int[] array,int target) {
        int start,mid,end;
        start=0;
        boolean temp=false;
        end=array.length-1;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(target>array[mid])
            {
                start=mid+1;
            }
            else if(target<array[mid])
            {
                end=mid-1;
            }
            else
            {
                temp=true;
                System.out.println("Found!!");
                break;
            }

        }
        if(!temp)
        {
            System.out.println("NotFound!!");
        }
    }

    public static void descendingBinarysearch(int[] array,int target) {
        int start,mid,end;
        start=0;
        boolean temp=false;
        end=array.length-1;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(target<array[mid])
            {
                start=mid+1;
            }
            else if(target>array[mid])
            {
                end=mid-1;
            }
            else
            {
                temp=true;
                System.out.println("Found!!");
                break;
            }

        }
        if(!temp)
        {
            System.out.println("NotFound!!");
        }
    }

}
