/*Unordered Maps---->Hashtable
operations
i)insert
ii)delete
iii)search
every operation works in O(1) time on an average
*/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
	
	unordered_map<string,int>um;
	//insert
	um.insert(make_pair("Mango",150));
	um["Banana"]=60;
	um["Grapes"]=80;
	um["Orange"]=90;
	//print
	for(auto it=um.begin();it!=um.end();it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}
	//delete
    string fruit;
    cin>>fruit;
    um.erase(fruit);
    //search
    if(um.count(fruit)){
    	cout<<"price is "<<um[fruit]<<endl;
    	
	}
	else{
		cout<<fruit<<" not found"<<endl;
	}
	return 0;
}
