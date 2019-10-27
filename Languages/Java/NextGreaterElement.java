public static int[] ngeR(int[] arr){
		 int[] ans = new int[arr.length];
		 Stack<Integer> st = new Stack<>();
		 ans[arr.length-1] = -1;
		 st.push(arr[arr.length-1]);
		 for(int i = arr.length-2 ; i >=0; i-- ){

			 while(st.size()>0 && st.peek()<arr[i]){
				// since we want to find the next greatest elemnet, so pop out the smaller element 
				 st.pop();
			 }
				/////// EVEN THOUGH WHILE INSIDE IF , STILL complexity is O(n)  //
			 ans[i] = st.size()>0 ? st.peek() : -1;
			 st.push(arr[i]);
		 }
		 return ans;
	 }
