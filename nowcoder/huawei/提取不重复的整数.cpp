#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

int main(){
    using namespace std;
    string str;
    /*while(getline(cin,str)){
        unordered_set<char> s;
        vector<char> vec;
        for(int i = str.size()-1; i >=0; i--){
            if(s.count(str[i]) == 0){
                vec.push_back(str[i]);
                s.insert(str[i]);
            }
        }
        //cout <<s.size() <<endl;
        for(auto i = vec.begin(); i != vec.end(); i++)
            cout << *i;
        cout <<endl;
    }*/
    while(getline(cin,str)){
        int a[10] = {0};
        for(int i = str.size()-1; i >=0 ; i--){
            if(a[str[i]-'0'] == 0){
                cout << str[i];
                a[str[i]-'0']++;
            }
        }
    }
}
