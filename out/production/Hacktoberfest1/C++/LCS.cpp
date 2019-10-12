#include <iostream>
#include <stdio.h>
using namespace std;
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int main() {
	int testCases,m,n;
	cin>>testCases;
	for(int itr=0;itr<testCases;itr++){
	    cin>>m>>n;
	    int LCS[m+1][n+1];
	    char X[m],Y[n];
	    for(int i=0;i<m;i++){
            cin>>X[i];
	    }
	    for(int i=0;i<n;i++){
            cin>>Y[i];
	    }

	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0 || j==0)
	                LCS[i][j]=0;
	            else if(X[i-1]==Y[j-1])
	                LCS[i][j]=LCS[i-1][j-1]+1;
	            else
	                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
	        }

	    }
	    cout<<LCS[m][n]<<endl;
	}
	return 0;
}
