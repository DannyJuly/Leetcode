
//hashmap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        if(nums.empty()) return 0;
        for(auto i : nums){
            if(m.count(i) > 0) m[i]++;
            else
                m[i] = 1;
        }
         for(auto i : nums){
             
             if(m[i] == 1)
                 return i;
         }
/*
         map<int,int>::iterator it;
         for (it = m.begin(); it != m.end(); it++)
         {
            if(it->second ==1) return it->first;
         }*/
        return nums[0];
    }
};

//https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
//explaination of this method.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos = 0;
        for(auto num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
           
        return ones;
    }
};


//general solution for elements appear k times except for one appears only m times.
//https://leetcode-cn.com/problems/single-number-ii/solution/tong-yong-jie-fa-gai-wen-ti-shi-shu-zu-zhong-mou-s/
//java
class Solution {
    public int singleNumber(int[] nums) {
        
        int ans = 0;
        int[]temp = new int[32];
        for(int num:nums)
        {
            int r = 1;
            int j = 31;
            while(j >= 0)
            {
                if((num&r) != 0)temp[j]++;
                j--;
                r = r << 1; 
            }
        }
        int r = 1;
        int j = 31;
        
        while(j >= 0)
        {
            if(temp[j]%3 != 0)
                ans = ans ^ r;
            r = r << 1;
            j--;
        }
        
        return ans;
    }
}

