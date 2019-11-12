#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

struct Count{
    char ch;
    int cnt;
    Count(char _ch,int _cnt):ch(_ch),cnt(_cnt){}
};
bool cmp2(const char & ch1, const char & ch2){
    return ch1 < ch2;
}

bool cmp(const pair<char,int> & c1,const pair<char,int> & c2){
    if(c1.second==c2.second)
        return c1.first < c2.first;
    return c1.second > c2.second;
}
int main(){
    string str;
    while(cin>>str){
        bool (*fn)(const char&,const char&) = cmp2;
       map<char,int,bool(*)(const char&,const char&) > mp(fn);
       for(auto ch : str){
           mp[ch]++;
       }
        vector<pair<char,int> > vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),cmp);
            
       for(auto &p : vec)
            cout << p.first;
        cout << endl;
    }
}
