//https://leetcode-cn.com/problems/binary-search/solution/704-er-fen-cha-zhao-cer-fen-mo-ban-by-ivan_allen/


int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (target <= nums[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return nums.empty() ? -1 : (target == nums[lo] ? lo : -1);
}
/*如果 hi = nums.size()，返回 target 应该插入的位置。你也可以把这个版本理解成左闭右开区间的查找。
这样算出来的 mid 在实际数组中是个右 mid，但是这个 mid 对于左半部分来说是个右开区间，对于右半部分来说是个左闭区间。

如果 hi = nums.size() - 1，也是返回元素应该插入的位置，但是如果 target 比所有元素都大，只能返回最后一个位置。*/


//only search, not insert
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1; // <-
    while (lo <= hi) { // <-
        int mid = lo + (hi - lo >> 1); // <-
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

