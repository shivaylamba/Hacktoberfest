//Bubble sort

class BubbleSort {
	void bsort(int arr[])
	{
		int n = arr.length;
    int i,j;
		for (i = 0; i < n - 1; i++){
			for (j = 0; j < n - i - 1; j++){
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
      }}
	}

	
	public static void main(String args[])
	{
		BubbleSort obj = new BubbleSort();
    Scanner sc = new Scanner(System.in);
    int n,i;
    n=sc.nextInt();
    int arr[] = new int[n];
    for(i=0; i<n; i++)
      arr[i]=sc.nextInt();
		obj.bsort(arr);
		System.out.println("Sorted array");
    for (int i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
    
	}
}
/* This code is contributed by Rajat Mishra */
