//priority_queue  its first element is always the greatest of the elements
class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int> >pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i=0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size()>k) 
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size)
            pq.pop();
        if(pq.size() < size)
            return -1;
        return pq.top();
    }
};

