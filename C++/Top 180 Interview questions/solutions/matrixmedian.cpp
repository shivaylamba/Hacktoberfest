int Solution::findMedian(vector<vector<int> > &A) {
	// very easy approach but uses extra space
    int n = A.size();
    int m = A[0].size();
    int k = (n*m)/2;
    
    vector<int>B;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            B.push_back(A[i][j]);
    A.clear();
    nth_element(B.begin(),B.begin()+k,B.end());
    // B.begin() + k gives us the nth elements like if we want the 5th element
    // B.begin() + k;
    return B[k];
}