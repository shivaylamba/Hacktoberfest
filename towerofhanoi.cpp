// note reallay a tower of hanoi problem as it uses 3 towers ( i made one of mine which uses 4 towers logic mostly same as for 3towers)

#include<bits/stdc++.h>
using namespace std;
void TOH(int a,int A,int B, int C,int D){
    if(a > 0){
        TOH(a-1,A,B,D,C);
        cout<<A<<"->"<<D<<endl;
        TOH(a-1,C,B,A,D);

    }
}
int main(){
    TOH(4,1,2,3,4);
}