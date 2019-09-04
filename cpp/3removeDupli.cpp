class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int i = 0,j = 0;
        while(i < nums.size() && j < nums.size()){
            if(nums[i] == nums[j])
                j++;
            else
                nums[++i] = nums[j++];
        }
        return i+1;
    }
};

class Solution {
    public int removeDuplicates(int[] nums) {
        // 使用双指针
        if(nums==null || nums.length == 1){
            return nums.length;
        }
        int i = 0,j =1;
        while(j<nums.length){
            if(nums[i]==nums[j]){
                j++;
            }else{
                i++;
                nums[i]=nums[j];
                j++;
            }
        }
        return i+1;
    }
}