//BF
class Solution {
public:
    int firstUniqChar(string s) {
        for(int i = 0; i < s.size() ; i++){
            int k = 0;
            while((s[i] != s[k] && k < s.size()) || k==i )
                k++;
            if(k == s.size())
                return i;
        }
        return -1;
    }
};

//bucket 
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v;
        v.resize(26,0);
        for(int i = 0; i< s.length(); ++i)           //0-25代表字母 见到一个字母就+1
        {
            v[s[i]-'a']++;
        }
        
        for(int i =0; i <s.length();++i)            //遍历原字符串，找到词频只有一次的就直接返回i
        {
            if(v[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

//hashmap 
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashmap;
        for(auto i : s){
            if(hashmap.count(i))    hashmap[i] += 1;
            else    hashmap[i] = 1;
        }
        for(int j = 0; s[j] != '\0'; ++ j)  if(hashmap[s[j]] == 1)  return j;
        return -1;
    }
};

