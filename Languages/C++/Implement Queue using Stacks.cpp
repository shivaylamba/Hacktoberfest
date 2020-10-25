class MyQueue {
public:
    //enque operation
    //mvi s1 to s2
    //push x to s1
    //mvi s2 to s1
    
    
    //dequeue
    //pop from s1
    stack<int> s1;
        stack<int> s2;
    /** Initialize your data structure here. */
    MyQueue() {
        // vector<int> Queue;
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = s1.top();
         s1.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (s1.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
