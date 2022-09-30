import java.util.* ;
public class MergeSort {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in) ;
		System.out.println("Enter size of the array") ;
		int n = in.nextInt() ;
		int []a = new int[n] ;
        System.out.println("Enter the elements in the array") ;
		for(int i=0 ; i<n ; i++) {
			a[i] = in.nextInt(); 
		}
		sort(a,0,n-1) ;
		for(int el : a) {
			System.out.print(el+" ");
		}
	}
	static void sort(int[] a , int l , int r) {
		if(l<r) {
			int mid = (l+r)/2; 
			sort(a,l,mid) ;
			sort(a,mid+1,r) ;
			merge(a,l,mid,r) ;
		}
	}
	static void merge(int[] a , int l , int  mid , int r) {
		int b[] = new int[r-l+1] ;
		int ptr1=l,ptr2=mid+1 ;
		int index=0 ;
		while(ptr1<=mid && ptr2<=r) {
			if(a[ptr1] < a[ptr2]) {
				b[index++] = a[ptr1++] ;
			}
			else {
				b[index++] = a[ptr2++] ;
			}
		}
		while(ptr1<=mid) {
			b[index++]=a[ptr1++] ;
		}
		while(ptr2<=r) {
			b[index++]=a[ptr2++] ;
		}
		index=0 ;
		for(int i=l ; i<=r ; i++) {
			a[i] = b[index++] ;
		}
	}
}