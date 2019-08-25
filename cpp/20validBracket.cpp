class Solution {
public:
    bool isValid(string s) {
        stack<char> str;   //using stack
        if(s.length()%2!=0) return false; //if the length of s is odd, return false
        for(int i=0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                str.push(s[i]);
            else
            {
                if(!str.empty())
                {
                    char t = str.top();
                    str.pop();
                    if(!((t=='(' && s[i]==')') || (t=='[' && s[i]==']') || (t=='{' && s[i]=='}')))
                        return false;
                }
                else
                    return false;
            }
        }
        if(str.empty()) return true;
        else return false;
    }
};


//https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode/
