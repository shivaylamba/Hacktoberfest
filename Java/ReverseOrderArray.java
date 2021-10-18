import java.io.*;
import java.util.*;
class ReverseOrderArray{
	public static void main(String args[]){
		int n;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the value of n");
		n=sc.nextInt();
		int arr[]=new int[n];
		int arr1[]=new int[n];
		for(int i=0;i<n;i++){
			arr[i]=sc.nextInt();
		}
		System.out.println("The Array Before in reverse Order");
		for(int j=0;j<n;j++){
			System.out.print(arr[j]+"\t");
		}
		System.out.println("\n The Array After in reverse Order");
		int last=n-1;
		for(int k=0;k<n;k++){
			if(last>=0){
			arr1[k]=arr[last];
			last--;
			}
		}
		for(int l=0;l<n;l++){
			System.out.print(arr1[l]+"\t");
		}
	}
}

			
		
