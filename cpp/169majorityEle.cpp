// Boyer-Moore 投票算法
//如果我们把众数记为 +1+1 ，把其他数记为 -1−1 ，将它们全部加起来，
//显然和大于 0 ，从结果本身我们可以看出众数比其他数多。
class Solution {
public:
     int majorityElement(vector<int>& nums) {
        int vote=0;
        int mode ;
        for(int i=0; i < nums.size(); i++){
            if( vote == 0)
                mode = nums[i];
            vote += (nums[i] == mode) ? 1: -1;

        }
        return mode;
    }
};

//先排序,再找中位数
class Solution {
public:
     int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());   //降序 sort(nums.rbegin(),nums.rend())
        return nums[nums.size()/2];
    }
};
