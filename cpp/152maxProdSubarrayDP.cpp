//DP  4ms  9.3mb
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int,int> > dp(nums.size(),make_pair(0,0));
        int ans = nums[0];
        dp[0] = make_pair(nums[0],nums[0]); 
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(dp[i-1].first,dp[i-1].second);
            }
            dp[i].first = min(nums[i],nums[i]*dp[i-1].first);
            dp[i].second = max(nums[i],nums[i]*dp [i-1].second);
            ans = max(ans,dp[i].second);
        }
        
        return ans;
    }
};


//dp 12ms 8.9mb
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, imax = 1, imin = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(imax,imin);
            }
            
            imax = max(imax*nums[i],nums[i]);
            imin = min(imin*nums[i],nums[i]);
            ans = max(ans,imax);
        }
        
        return ans;
    }
};
