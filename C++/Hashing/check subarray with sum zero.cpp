/*Check weather a array contains a subarray whose sum is 0 or not
example 6,-1,2,-1,1
here,-1+1=0
print true if there is a array like this otherwise false

1)first approach- Bruteforce 
here take two ponters i and j and compute sum every time.
time complexity- O(N^3)

2)second approach-Comulative sum(prefix sum)
ex. the array becomes 6,5,7,6,7
sum(i+1,j)=cum_sum(j)-cum_sum(i)  ,    for sum=0 cum_sum(j)=cum_sum(i)
7=7 , so subbarray with 0 sum exist
time complexity-O(N^2)

3)third approach- repeating or not / hashmap or unordered_map(int,bool) or unordered_set(int) to check weather a no. is repeating or not
time complexity - O(N)

*/

#include<iostream>
#include<unordered_set>
using namespace std;
bool check_sum(int arr[],int n){
	unordered_set<int>s;
	//first compute prefix sum
	int pre=0;
	for(int i=0;i<n;i++){
		pre+=arr[i];
		//check if the sum was already present in the set
		if(pre==0 or s.find(pre)!=s.end()){
			return true;
		}
		
		s.insert(pre);
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(check_sum(arr,n)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}


