int rowWithMax1s(vector<vector<int> > arr, int row, int col) {
	    int j = col  - 1;
	    int answer = -1;
	    // calculating for the first row
	    while(j>=0 && arr[0][j]==1){
	         j--;
	         answer = 0;
	    }
	    // counting the first index of the 1 row
	    for(int i = 1; i < row ; i++)
	    {
	        while(j>=0 && arr[i][j]==1)
	        {
	            j--;
	            answer = i;
	        }
	    }
	    return answer;
	}
	// this is same as interactive grid