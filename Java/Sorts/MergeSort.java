import java.util.Arrays;

public class MergeSort {
      static int[] temp;
      static  int count=0;
    public static void main(String []args)
    {

        int[] arr ={174,165,142,212,254,369,48,145,163,258,38,360,224,242,30,279,317,36,191,343,289,107,41,443,265,149,447,306,391,230,371,351,7,102};
        temp=new int[arr.length];
        mergeSort(arr,0,arr.length-1);
        System.out.println(count); //Inversion count means no of swap required
        System.out.println(Arrays.toString(arr));
    }

    private static void mergeSort(int[] arr, int l, int h) {
        if(l<h) {
           int mid=(l+h)/2;
           mergeSort(arr,l,mid);
           mergeSort(arr,mid+1,h);
           mergeSorted(arr,l,mid,h);
        }
    }

    private static void mergeSorted(int[] arr, int l, int mid, int h) {
        int i,j=mid+1,k;
        i=k=l;
        while(i<mid+1 && j<h+1 )
        {
            if(arr[i]<=arr[j])
                temp[k++]=arr[i++];
            else
            {
                temp[k++]=arr[j++];
                count+=(mid-i+1);
            }
        }
        while (i<mid+1) temp[k++]=arr[i++];
        while (j<h+1) temp[k++]=arr[j++];
       for(i=l;i<h+1;i++)
       {
           arr[i]=temp[i];
       }
    }
}
