//76ms BS
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1;
        int lack = 0;
        int first = nums[0];
        if((nums[nums.size()-1]-nums[0]-nums.size()+1) <k)
            return first + high + k;
        while(low < high){
            int mid = (low + high) /2;
            lack = nums[mid] - first - mid;
            if(lack >= k)
                high = mid;
            else
                low = mid + 1;
        }
        while((nums[low] - nums[low-1])==1)
            low--;
        return first + high + k - 1;
        
    }
};


//first create a lack vector.
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        vector<int> lacks(1,0);
        int first = nums[0];
        int j = 0;
        for(int i = 1; i < nums.size(); i++)
            lacks.push_back(nums[i] - first - i);
        if(k > lacks.back())
            return nums.back()+ k -lacks.back();
        while(k > lacks[j])
            j++;
        return nums.front() + j+k-1;
        
    }
};