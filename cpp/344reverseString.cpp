class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        for(int i=0; i<s.size()/2; i++){
            tmp = s.at(i);
            s.at(i)=s[s.size()-i-1] ;
            s[s.size()-i-1] =tmp;
            
        }
    }
};

//双指针
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while(i<j)
        {
            swap(s[i],s[j]);
            ++ i;
            -- j;
        }
    }

};

//STL
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.begin()+s.size());
    }
};