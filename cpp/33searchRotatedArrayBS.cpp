//binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};


//Find the pivot first, then binary search
class Solution {
public:
    int findPivot(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] < nums[right])
            return 0;
        
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[mid+1])
                return mid + 1;
            else{
                if(nums[left] < nums[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            
        }
        return left;
    }
    
    int binarySearch(vector<int>& nums,int left, int right,int target){
        if(left > right)
            return -1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if(nums[left] == target)
            return left;
        else
            return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int pivot = findPivot(nums);
        int index;
        if(target == nums[0])
            return 0;
        if(pivot == 0)
            return binarySearch(nums,0, nums.size()-1,target);
        if(target > nums[0])
            index = binarySearch(nums,0, pivot - 1,target);
        else
            index = binarySearch(nums,pivot, nums.size()-1 ,target);
        return index;
    }
};
