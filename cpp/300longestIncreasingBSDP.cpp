//DP 56ms O(N2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int ans = 1;
        vector<int> cell(1,1);
        for(int i = 1; i < nums.size(); i++){
            int maxlen = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    maxlen = max(maxlen,cell[j]+1);
                }                 
            }
            cell.push_back(maxlen);
            ans = max(ans,maxlen);
        }
        return ans;
        
    }
};

//DP+BS  O(nlogn) 8ms
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size() == 0) 
            return 0;
        vector<int> ans(1,nums[0]);
        for(int i = 1; i< nums.size() ;i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            
            int low = 0, high = ans.size() - 1;
            while(low < high){
                int mid = low + (high - low) / 2;
                if(ans[mid] >= nums[i])
                    high = mid;
                else
                    low = mid + 1;                 
            }
            ans[low] = nums[i];
        }
        return ans.size();
    }
};
