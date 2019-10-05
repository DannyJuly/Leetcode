class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> a{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> c;
        if(digits.empty())
            return c;
        c.push_back("");
        for (int i=0;i<digits.size();i++)
        {
            int res=digits[i]-'2';//当前按键对应的字符串索引
            int len=c.size();     //前一次处理好的字符串数
            for(int i = 0;i<len;i++)//遍历前一次处理好的字符串
            {
                for (auto m:a[res])//遍历按键对应字符
                {
                    c.push_back(c[i]+m);//将每一种组合放到末端
                }
            }
            c.erase(c.begin(),c.begin()+len);//清除前一次的组合
        }
       return c;
    }
};

//dfs
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return vector<string> {};
        vector<string> ans;
        string tmp;
        int len = digits.size();
        unordered_map<int,string> nums ( { {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"} } );
        helper(tmp, ans, nums, 0, digits);
        return ans;
    }    
    void helper(string &tmp, vector<string> & str, unordered_map<int,string> &nums, int index, string & digits){
        if(index == digits.size()){
            str.push_back(tmp);           
            return;
        }               
        for(auto i : nums[digits[index] - '0']){
            tmp.push_back(i);
            helper(tmp, str, nums, index+1 ,digits);
            tmp.erase(tmp.end()-1);
        }
    }
        
};