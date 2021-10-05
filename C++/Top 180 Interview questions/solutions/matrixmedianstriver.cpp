int Solution::findMedian(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    int mi=INT_MAX,ma=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mi=min(mi,a[i][0]);
    }
    for(int i=0;i<n;i++)
    {
        ma=max(ma,a[i][m-1]);
    }
    int ind=((n*m))/2;
    while(mi<=ma)
    {
        int mid=mi+(ma-mi)/2;
        int count=0;
        for(int i=0;i<n;i++)
        {
            count=count+upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
        }
         if(count<=ind)
             mi=mid+1;
           else
             ma=mid-1;
    }
    return mi;
}
