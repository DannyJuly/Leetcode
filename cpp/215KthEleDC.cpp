class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

//min stack
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto it:nums){
            q.push(it);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};

//DC && quick sort
class Solution {
public:
   int findKthLargest(vector& nums, int k) {
       int low = 0, high = nums.size() - 1, mid = 0;
       while (low <= high) {
           mid = partition(nums, low, high);
           if (mid == k - 1) return nums[mid];
           else if (mid > k - 1) high = mid - 1;
           else low = mid + 1;
       }
       //  实际上返回 -1 代表没有第 k 大的数，这里不存在
       return -1;
   }
   
   int partition(vector& nums, int low, int high) {
       int left = low + 1, right = high;
       swap(nums[low], nums[(low + high) / 2]);
       int bound = nums[low];
       //  双指针，快速排序，交换不符合条件的数据
       while (left <= right) {
           	while (left < high && nums[left] >= bound) 
           		left++;
           	while (nums[right] < bound) 
           		right--;
			if (left < right)    //it should not include = since when the bound is smaller than any other element
				swap(nums[left++], nums[right--]);
			else break;
       }
       //  将bound放到换分完成后的两个数组之间，作为边界, 返回bound的位次
       swap(nums[low], nums[right]);
       return right;
   }
};

