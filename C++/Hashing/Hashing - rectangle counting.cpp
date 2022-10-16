/* COUNT RECTANGLES
Given N cartesian points , find the number of axis parallel rectangles that can be formed by them
points=[[0,0],[0,1],[1,1],[1,0],[2,1],[2,0],[3,1],[3,0]]
*/

#include<iostream>
#include<set>
#include<vector>
using namespace std;
class point{
public:
	int x,y;
	point(){
		
	}
	point(int x,int y){
		this->x=x;
		this->y=y;
	}
};
class compare{
public:
	bool operator()(point p1,point p2){
		if(p1.x==p2.x){
			return p1.y<p2.y;
		}
		return p1.x<p2.x;
	}
	
};

int count_rect(vector<point> coords){
	int N=coords.size();
	//insert all points in the sets
	set<point,compare>s;
	for(auto p:coods){
		s.insert(p);
	}
	//run two loops
	int ans=0;
	for(auto it=s.begin();it!=prev(s.end());it++){
		for(auto jt=next(it);jt!=s.end();jt++){
			point p1=*it;
			point p2=*jt;
			
			if(p2.x==p1.x or p2.y==p1.y){
				continue;
			}
			point p3(p2.x,p1.y);
			point p4(p1.x,p2.y);
			if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
				ans++;
			}
		}
	}
	return ans/2;
	
}
int main(){
	int m;
	cin>>m;
	vector<point> coords;
	while(m--){
		int x,y;
		cin>>x>>y;
		point p(x,y);
		coords.push_back(p);
	}
	cout<<count_rect(coords);
	
	
	return 0;
}
