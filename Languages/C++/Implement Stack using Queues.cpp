class MyStack {
public:
    /** Initialize your data structure here. */
    //
    
    queue<int> q1;
    queue<int> q2;
    int size;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        size++;
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int> q;
        q=q1;
        q1=q2;
        q2=q;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    //pop elements::
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
