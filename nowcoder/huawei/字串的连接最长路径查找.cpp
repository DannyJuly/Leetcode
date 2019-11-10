#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

bool cmp(const std::string &s1, const std::string & s2){
    return s1 < s2;
}
int main(){
    using namespace std;
    vector<string> vec;
    int num;
    while(cin >> num){
        string input;
        for(int i = 0; i < num; i++){
            cin >> input;
            vec.push_back(input);
        }
        sort(vec.begin(),vec.end(),cmp);
        for(auto i : vec){
            cout << i << endl;
        }
            
    }
}
