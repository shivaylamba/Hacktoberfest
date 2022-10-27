#include<bits/stdc++.h>

  using namespace std;


  void solve(int a[], int n, int sum)
{
    int i,j;
    
     int dp[n+1][sum+1];
    
    for(i=0;i<=n;i++)
      dp[i][0]=1;
      
      for(j=0;j<=n;j++)
        dp[0][j]=0;
        
          for(i=1;i<=n;i++)
       
        {
              for(j=1;j<=sum;j++)
            
            {
              if(j<a[i])  
               dp[i][j]=dp[i-1][j];
               
               else
                 dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]];
            }
        }
        
        if(dp[n][sum]==1)
          cout<<"Possible"<<endl;
          
         else
           cout<<"Not Possible"<<endl;
}

 int main()
 {
     int n;
      cin>>n;
      
      int a[n];
      
        for(long i=0;i<n;i++)
      {
         cin>>a[i]; 
      }
      
        int sum;
        cin>>sum;
        
          solve(a,n,sum);
 }
