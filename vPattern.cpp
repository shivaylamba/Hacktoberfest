#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  int i,j;
  char ch;
  cin>>ch; 
  
  if(ch == 'V') {
  for(i=1; i<=5; i++){
  	
  	for(j=1; j<=10; j++){
  		
  		if(j > 5){
  				cout<<"";
  			
  			if(11-j<=i){

  			  cout<<11-j;
  			
			  }else{
			  	cout<<"  ";
			  }
  			
		
		  }else{
		 
		  	if(i>=j){
			
			 	cout<<j<<"";
			 
			  }else{
			  	cout<<"";
			  }
			
		  }
  		
  		
	  }
  	
  	cout<<endl;
  	
  }
  }
  return 0;
}
