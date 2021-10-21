#include<iostream>
#include<vector>
using namespace std;

vector<string> ratinmazewithreturntype(int sr,int sc,int er,int ec){
    if(sc==ec && sr==er){
        vector<string>base;
        base.push_back("");
        return base;
    }
    vector<string>myans;
    if(sc+1<=ec){
        vector<string>left=ratinmazewithreturntype(sr,sc+1,er,ec);
        for(int i=0;i<left.size();i++){
            myans.push_back("H"+left[i]);
        }
    }
    if(sr+1<=er){
        vector<string>down=ratinmazewithreturntype(sr+1,sc,er,ec);
        for(int i=0;i<down.size();i++){
            myans.push_back("V"+down[i]);
        }
    }
    return myans;
}
int main(){
    vector<string>ans=ratinmazewithreturntype(0,0,2,2);
    for(auto ele:ans){
        cout<<ele<<endl;
    }
}
