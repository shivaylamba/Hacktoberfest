#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i, j;
  
  for(i=1; i<=5; i++){
    
    for(j=5; j>0; j--){
      int temp;
     	if(i==j){

      	cout<<i;

      	}else{
      		if(i>j){
      			
      			if(i-j==1){
      			temp = i+1;
      		    cout<<temp;
      		    }else{
					cout<<++temp;	
				}
      		    
			  
			  }else{
			  	cout<<" ";
			  }
	    }
	  	
	  }
      cout<<"\n";
    }
  
  return 0;
}
