class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.empty())    return ans; //输入为空，输出空ans
        int arr = strs.size();
        string min = strs[0];
        for(int i = 1; i < arr; ++ i) //找到最短字符串
        {
            if(strs[i].size() < min.size())
                min = strs[i];
        }
        for(int j = 0; j < min.size(); ++ j) //从第一个字符开始对比，若都一样，ans加上该字符，若不一样，返回答案；
        {
            for(int m = 0; m < arr; ++m)
            {
                if(min[j] != strs[m][j])
                    return ans;
            }
            ans = ans + min[j];
        }
        return ans;
    }
};

