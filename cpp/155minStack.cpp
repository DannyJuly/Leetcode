// two stacks

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    //
    void push(int x) {
        s.push(x);
        //如果压入的值小于辅助栈的栈顶元素值，则更新最小值（辅助栈压入新元素），否则辅助栈再次压入其栈顶元素
        if(smin.empty()||x<=smin.top())
            smin.push(x);
        else
            smin.push(smin.top());
    }
    
    void pop() {
        s.pop();
        smin.pop();//出栈后，更新辅助栈
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return smin.top();//辅助栈栈顶元素为最小值
    }
private:
    stack<int> s;
    stack<int> smin;//辅助栈
};


//主要思想：在栈的最顶端，一直设置一个存放最小值的空间
//pop,push,top组件分别需要配合这个最小值的空间
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int rec = 0;
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            s.push(x);
            rec = 1;
        }else{
            int tmp = s.top();
            s.pop();
            s.push(x);
            if(tmp > x){
                s.push(x);
                rec = 1;
            }
            else if (tmp < x){
                s.push(tmp);
            }
            else if (tmp == x){
                s.push(tmp);
                rec++;
            }
        }
    }
    
    void pop() {
        vector<int> arr;
        int tmpmin = s.top();
        s.pop(); // pop min
        int tmpval = s.top();
        s.pop(); // pop val
        if (tmpmin == tmpval)
            rec--;
        if (rec==0){
            tmpmin = INT_MAX;
            while(!s.empty()){
                arr.push_back(s.top());
                tmpmin = min(tmpmin, s.top());
                s.pop();
            }
            for(int i=arr.size()-1;i>=0;i--)
                s.push(arr[i]);
            rec = 1;
        }
        if(!s.empty()){
            s.push(tmpmin);
        }
        
    }
    
    int top() {
        int tmpmin = s.top();
        s.pop();
        int tmp = s.top();
        s.push(tmpmin);
        return tmp;
    }
    
    int getMin() {
        return s.top();
    }
};

