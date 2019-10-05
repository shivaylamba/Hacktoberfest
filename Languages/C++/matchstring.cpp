#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
cin.get();
char arr[100][100];
for(int i=0;i<n;i++){
    cin.getline(arr[i],100);
}
char word[100];
cin.getline(word,100);
for(int i=0;i<n;i++){
    bool isMatch = true;
    for(int j=0;arr[i][j]!='\0' || word[j]!='\0';j++){
        if(arr[i][j]!=word[j]){
            isMatch = false;
            break;
        }
    }
    if(isMatch){
        cout<<"found"<<endl;
        return 0;
    }
}
cout<<"Not found"<<endl;
}
