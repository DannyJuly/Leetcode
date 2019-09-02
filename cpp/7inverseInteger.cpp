
/4ms
class Solution {
public:
    int reverse(int x) {
        int i = 1;
        if(x<0) i=-1;
        string s = to_string(x);
        std::reverse(s.begin(),s.end());
        while(s[0] == '0')
            s.erase(s.begin());
        if( i*atol(s.c_str())>INT_MAX || i*atol(s.c_str())<INT_MIN)
            return 0;
        return i*atoi(s.c_str());
    }
};

//4ms
class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev *10> INT_MAX || (rev*10 == INT_MAX  && pop > 7)) return 0;
            if (rev*10 < INT_MIN || (rev*10 == INT_MIN  && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return int(rev);
    }
};

