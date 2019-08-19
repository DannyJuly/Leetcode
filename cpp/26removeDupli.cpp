class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp = 1;
        if(nums.size()<=1)
            return nums.size();
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] != nums[i+1]){
                nums[temp] = nums[i+1];   //if i is not equal to i+1, keep it.
                temp++;
            }
        }
        return temp;
    }
    
};