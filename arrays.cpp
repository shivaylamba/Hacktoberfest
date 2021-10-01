#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n=1;
    while(n){
        int t;
        cout<<"Choose an option: "<<endl<<"\t Insert an element [1]"<<endl<<"\t Print the array [2]"<<endl<<"\t Print the array in reverse order [3]"<<endl<<"\t Reverse array elements [4]"<<endl<<"\t Reverse first half of the elements [5]"<<endl<<"\t Search for an element in the array [6]"<<endl<<"\t Sort the array [7]"<<endl<<"\t Exit [8]"<<endl;
        cin>>t;
        switch(t){
            case 1:
                int c;
                cout<<"Enter the element to be inserted: ";
                cin>>c;
                v.push_back(c);
                break;
            case 2:
                for(int i=0;i<v.size();i++){
                    cout<<v[i]<<" ";
                }
                break;
            case 3:
                for(int i=v.size()-1;i>=0;i--){
                    cout<<v[i]<<" ";
                }
                break;
            case 4:
                for(int i=0;i<v.size()/2;i++){
                    int f=v[i];
                    v[i]=v[v.size()-i-1];
                    v[v.size()-i-1]=f;
                }
                break;
            case 5:
                for(int i=0;i<v.size()/4;i++){
                    int f=v[i];
                    v[i]=v[v.size()/2-i-1];
                    v[v.size()/2-i-1]=f;
                }
                break;
            case 6:
                int k;
                cout<<"Enter the element to be searched: ";
                cin>>k;
                for(int i=0;i<v.size();i++){
                    if(v[i]==k){
                        cout<<"Element found at position "<<i+1<<endl;
                        break;
                    }
                    else if(v[i]!=k && i==v.size()-1){
                        cout<<"Element not found!"<<endl;
                    }
                }
                break;
            case 7:
                sort(v.begin(),v.end());
                break;
            case 8:
                n=0;
                break;
        }
    }
    return 0;
}
