class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0], sum = 0;
        for(auto i:nums){
            sum += i;
            ans = max(sum, ans);
            sum = max(sum,0);
        }
        return ans;
    }
};         //DP problem

