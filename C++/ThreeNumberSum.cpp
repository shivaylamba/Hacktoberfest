#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
 vector<vector<int>> a;
 sort(array.begin(),array.end());
 for(int i=0;i<array.size()-2;i++){
	  vector<int>b;
	  int L=i+1;
	  int R=array.size()-1;
	  int x=targetSum;
	  while(L<R){
		int c=array[L]+array[R]+array[i];

	  if(c==x){
      a.push_back({array[i],array[L],array[R]}); 
			L++;
			R--;
		}
		if(c<x)L++;
	  if(c>x)R--;
		}
 }
	
 return a;
}
