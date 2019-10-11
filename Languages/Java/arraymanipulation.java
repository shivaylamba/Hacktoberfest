package hackerrank_medium;

import java.util.Arrays;
import java.util.Scanner;

public class arraymanipulation {
    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int m=scn.nextInt();
        long[] arr=new long[n];
        long max=0;
        for(int i=0;i<m;i++){
            int i1=scn.nextInt()-1;
            int i2=scn.nextInt()-1;
            long k=scn.nextLong();
            arr[i1]+=k;
            if(!(i2==arr.length-1)){
                arr[i2+1]-=k;
            }
        }
        for(int i=1;i<arr.length;i++){
            arr[i]+=arr[i-1];
            if(arr[i]>max){
                max=arr[i];
            }
        }

        System.out.println(max);
    }
}
