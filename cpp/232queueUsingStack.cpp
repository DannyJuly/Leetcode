class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!nums.empty()){
            temp.push(nums.top());
            nums.pop();
        }      
        temp.push(x);
        while(!temp.empty()){
            nums.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
       // if(nums.empty()) return 0;
        num = nums.top();
        nums.pop();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        //if(nums.empty()) return 0;
        return nums.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return nums.empty();
    }
    private:
    stack<int> nums;
    stack<int> temp;
    int num;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */