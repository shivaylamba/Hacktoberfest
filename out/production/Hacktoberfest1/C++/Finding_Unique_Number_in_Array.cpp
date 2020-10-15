#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> A{1,2,2,3,1};

    int temp=A[0];
    for(int i=1;i<A.size();i++){

        temp=temp^A[i];
        cout<<temp<<endl;
    }
    int abc = 4^2;
    cout<<abc;
}
