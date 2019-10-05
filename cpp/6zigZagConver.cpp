class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int ivl = (numRows-1) * 2;
        int len = s.size();
        string ans;
        int i = 0;
        for(int j = 0; j < numRows - 1; j++){
            i = j;
            while( i < s.size()){
                if((i - j) % ivl == 0){
                    ans.push_back(s[i]);
                    i += ivl - 2 * j;                     
                }
                else{
                    ans.push_back(s[i]);
                    i += 2*j;                         
                }                              
            }
        }
        i = numRows-1;
        while(i < s.size()){
            ans.push_back(s[i]);
            i += ivl;
        }
        return ans;
    }
};