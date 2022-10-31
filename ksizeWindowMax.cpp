#include<iostream>
#include<stack>

using namespace std;

int main(){
   int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k;
    cin>>k;
    int nge[n];

    stack<int> st;

    nge[n-1]=-1;
    st.push(a[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=a[i] ){
            st.pop();
        }
        if(st.empty()){
            nge[i]=-1;
        }else{
            nge[i]=st.top();
        }
        st.push(a[i]);
    }
  int j=0;
    for(int i=0;i<n-k;i++){
         while(j<i){
            j=i;
        }
        j=i;
        while(nge[j]<i+k){
            j=nge[j];
        }
        cout<<a[j]<<" ";
    }
return 0;
    }
