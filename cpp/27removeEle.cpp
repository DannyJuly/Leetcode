class Solution {
public:
    //solution 1, using iterator, the most powerful
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator itr = nums.begin();
        int length = nums.size();
        while(itr!=nums.end()){
            if(*itr == val){
                itr = nums.erase(itr);
                length--;
            }              
            else
                itr++;
        }
        return length;
        

    }
    //solution 2
    int removeElement2(vector<int>& nums, int val) {
    int cnt = 0;
    for(int i = 0 ; i < nums.size() ; ++i) {
        if(nums[i] == val)
            cnt++;
        else
            nums[i-cnt] = nums[i];
    }
    return nums.size()-cnt;
}
};