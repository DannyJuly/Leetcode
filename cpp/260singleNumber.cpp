vector<int> singleNumber(vector<int>& nums) 
{
    unordered_set<int> numbers;
    for (int number : nums)
    {
        //在 C++ 中，通过 unordered_set 的 insert 方法添加元素时，将返回一个 pair<iterator, bool> 对象
        //其 second 为一布尔类型的值，标识是否添加成功
        //注意逻辑非(!)操作符
        if (!numbers.insert(number).second)
            numbers.erase(number);;//重复便移除
    }
    //还要转换
    vector<int> result(numbers.begin(),numbers.end());
    return result;
}

//https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C%2B%2BJava-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums)
            ans ^= i;
        ans &= -ans;
        vector<int> number(2,0);
        for(int i : nums){
            if((ans & i) == 0 )
                number[0] ^= i;
            else
                number[1] ^= i;
            
        }
        return number;
    }
};