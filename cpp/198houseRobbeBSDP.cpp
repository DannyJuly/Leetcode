class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums.front();
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        return dp[nums.size()-1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        //vector<int> dp(nums.size(),0);
        if(nums.empty()) return 0;
        //if(nums.size() == 1) return nums.front();
        int premax = 0;
        int curmax = 0;
        int temp = 0;
        for(auto i: nums){
            temp = curmax;
            curmax = max(curmax, premax + i);
            premax = temp;
        }
            
        return curmax;
    }
};