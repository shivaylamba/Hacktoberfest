#include<iostream>
#include<stack>
using namespace std;

void insertAtButtom(stack<int> & s,int x){
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int y=s.top();
    s.pop();
    insertAtButtom(s,x);
    s.push(y);
}

void reverseStack(stack<int>&s)
{
    if(s.empty())
    {
        return;
    }
    int x=s.top();
    s.pop();
    reverseStack(s);
    insertAtButtom(s,x);
}


 int main(){
  stack<int>s;
  int n;
  cin>>n;
  int data;
  for(int i=0;i<n;i++)
  {
      cin>>data;
      s.push(data);
  }
  reverseStack(s);

  while(!s.empty())
  {
      cout<<s.top()<<endl;
      s.pop();

  }

  }
