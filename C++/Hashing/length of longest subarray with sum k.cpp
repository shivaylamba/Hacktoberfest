/*logest subarray with sum k
let the cummulatice sum array be
c1,c2,c3,.....c(i).....c(j)....cn
the sum between i and j is c(j)-c(i)=k
we can use map here
find an index whose c(i)=c(j)-k
where c(j) is the current index and we have to find c(i) in the remaining array accordingly for every c(j) 
and when the c(i)=c(j)-k then find length
example - 6 is the current sum and if an index with sum 6-k is present than subarray with sum k exist else not.
and if current index sum=k (c(j)=k) then length=j+1

*/

#include<iostream>
#include<unordered_map>
using namespace std;
int longest_subarray_sum(int arr[],int n,int k){
	unordered_map<int,int> m;
	int pre=0;
	int len=0;
	for(int i=0;i<n;i++){
		pre+=arr[i];
		if(pre==k){
			len=max(len,i+1);
		}
		if(m.find(pre-k)!=m.end()){
			len=max(len,i-m[pre-k]);
		}
		else{
			//store the first occ. if the no. is repeating
			m[pre]=i;
		}
	}
	return len;
	
}
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[n];
	}
	cout<<longest_subarray_sum(arr,n,k)<<endl;
	
	
	return 0;
}
