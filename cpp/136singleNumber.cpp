//hashmap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> bobo;
        int ans;
        for(auto i : nums){
            if(bobo.count(i))   bobo.erase(i);
            else    bobo.insert(i);
        }
        for(auto j : bobo)  ans = j;
        return ans;
    }
};

//sort, then double pointer i,j
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 1; j < nums.size(); i += 2, j += 2){
            if(nums[i] != nums[j])  return nums[i];
        }
        return nums[nums.size() - 1];
    }
};

//exclusive or 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); ++ i){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

