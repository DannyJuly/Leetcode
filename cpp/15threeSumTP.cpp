//three pointer
class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int left = low+1, right = high;
        swap(nums[low],nums[(low+high)/2]);
        int bound = nums[low];
        while(left <= right){
            while(left < right && nums[left] <= bound)
                left++;
            while(nums[right] > bound)
                right--;
            if(left < right)
                swap(nums[left++],nums[right--]);
            else
                break;
        }
        swap(nums[right],nums[low]);
        cout<<right<<endl;
        return right;
    }
    
    void quickSort(vector<int>& nums, int low, int high){
        int m;
        if(low < high){
            m = partition(nums,low,high);
            quickSort(nums,low, m -1);
            quickSort(nums,m+1,high);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        vector<vector<int> > ans;
        int low =0, high = nums.size()-1;
        //quickSort(nums, low, high);
        sort(nums.begin(),nums.end());
        for(auto i:nums)
            cout<<i<<endl;
        if(nums.front() > 0 || nums.back() < 0) return {};
        
        int i = 0;
        for(i; i<nums.size();i++){
            int fix = nums[i];
            if(fix > 0) break;
            if(i > 0 && fix==nums[i-1])
                continue;
            int l = i+1, r = nums.size()-1;
            
            while(l<r){
                if(nums[l]+nums[r] == -fix){
                    if(l == i+1 || r==nums.size()-1){
                        ans.push_back(vector<int> {nums[i],nums[l],nums[r]});
                        l++;r--;  
                    }
                    else if(nums[l] == nums[l-1])
                        l++;
                    else if(nums[r] == nums[r+1])
                        r--;
                    else{
                        ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                }
                else if(nums[l] + nums[r] < -fix)
                    l++;
                else
                    r--;
                
            }
            
        }
        
        return ans;
    }
};