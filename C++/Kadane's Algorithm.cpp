#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	
	int currsum=0;
	int maxsum=0;
	for(int i=0;i<n;i++){
	    currsum+=a[i];
	    if(currsum>0){
	        maxsum=max(maxsum,currsum);
	    }
	    else{
	        currsum=0;
	    }
	}
	cout<<maxsum<<endl;
	return 0;
}
