// we will have a value array and a weight array
 int weight[5];
 int value[5];
 int w//;
 // we will only be able to return t[n][w] only when
 // we loop it to n + 1, w + 1;
 int t[n+1][w+1];
 for(int i = 0 ; i < n +1 ; i++)
 {
 	for(int j = 0 ; j < n + 1 ; j++)
 	{
 		if(i==0 || j==0)
 			t[i][j] = 0;
 		else if(weight[i - 1]<=w)
 			t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]], t[i-1][j]);
 		else 
 			t[i][j] = t[i-1][j];
 	}
 }
 return t[n][w];
}