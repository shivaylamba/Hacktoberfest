#include <iostream>
#include <vector>
using namespace std;

//Implementation of Stack Data Structure using Vector

class Stack{
private:
    vector<int> v;    
public:
    void push(int data){
        v.push_back(data);
    }
    bool empty(){
        return v.size()==0;
    }
    void pop(){
        if(!empty()){
             v.pop_back();
        }
    }
    int top(){
        return v[v.size()-1];
    }
};

int main() {
    Stack s;

    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    //Try to print the content of the stack by popping each element
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    

return 0;
}
