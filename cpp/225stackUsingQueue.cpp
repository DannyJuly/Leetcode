class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        //nothing to do
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        nums.push(x);
        //将前面的size-1个元素放到后面去
        for(int i = 0; i < nums.size() - 1; i++){
            nums.push(nums.front());
            nums.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num = nums.front();
        nums.pop();
        return num;
    }
    
    /** Get the top element. */
    int top() {
        return nums.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return nums.empty();
    }
private:
    queue<int> nums;
};
