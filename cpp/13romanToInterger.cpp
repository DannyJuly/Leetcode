
//map 效率十分低，占用内存大，但方便
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)];
        for(int i=1; i<s.size(); ++i){
            string two = s.substr(i-1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};

//map 简化
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000},{'\0',0}};
      int value=0;
      for(int i = 0; i < s.size(); i++){
          if(m[s[i]] < m[s[i+1]])
            value-=m[s[i]];
          else
            value += m[s[i]];        
      }  
      return value;     
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int x=0;
        char a[7]{'M','D','C','L','X','V','I'};
        int c[7]{1000,500,100,50,10,5,1};
        for(int i=0;i<s.size()-1;i++)
        {
            int k=0;
            int n=0;
            while(s[i]!=a[k]) k++;
            while(s[i+1]!=a[n]) n++;
            if(k<=n)
                x=x+c[k];
            else
                x=x-c[k];
        }
        int k=0;
        while(s[s.size()-1]!=a[k]) k++;
        x=x+c[k];
        return x;
    }
};

