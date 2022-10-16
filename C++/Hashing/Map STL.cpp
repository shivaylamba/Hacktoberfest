/*map is a associative container that stores maping between key and value
there are two types of maps in c++, first is map and second is unordered map.
operations-
i) insert(key,value)-insert
ii) search(key)-find
iii) delete(key)-erase
map is a self balanced binary tree, keys are ordered in maps.*/


#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	map<string,int>m;
	//insert
	m.insert(make_pair("mango",100));
	//another way to insert
	pair<string,int>p;
	p.first="apple";
	p.second=120;
	m.insert(p);
	//one more way to insert
	m["banana"]=80;
	
	string fruit;
	cin>>fruit;
	//update the price
	m[fruit]+=20;
	//find
	auto it=m.find(fruit);
	if(it!=m.end()){
		cout<<"price of "<<fruit<<" is "<<m[fruit]<<endl;
		
	}
	else{
		cout<<"fruit is not present"<<endl;
		
	}
	//erase
	m.erase(fruit);
	//another way to find a particular key
	//map stores unique keys only once
	//count function return 1 or 0 if a particular key is present or not
	if(m.count(fruit)){
		cout<<"price is "<<m[fruit]<<endl;
	}
	else{
		cout<<"could'nt found"<<endl;
		
	}
	//the only difference between find and count is that find return an iterator but count returns a integer
	
	m["litchi"]=60;
	m["pineapple"]=200;
	m["guava"]=150;
	
	//iterate over all the keys
	for(auto it=m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl;
	//for each loop
	for(auto p:m){
		cout<<p.first<<" : "<<p.second<<endl;
	}
	return 0;
	
	
	
}