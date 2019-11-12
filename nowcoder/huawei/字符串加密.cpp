#include <string>
#include <iostream>
#include <set>

using namespace std;

void eraseRep(string & str){
    
}

int main(){
    string str;
    string res;
    while(cin >> str >> res){
        //string alpha1 = "abcdefghijklmnopqrstuvwxyz";
        //set<char> se;
        string alpha2;
        for(int i = 0; i < str.size(); i++){
            if(alpha2.find(str[i]) == string::npos){
                alpha2.push_back(str[i]);
            }
        }
        
        for(int i = 'a'; i <= 'z'; i++){
            if(alpha2.find(i) == string::npos)
                alpha2.push_back(i);
        }
        
        for(int i = 0; i < res.size(); i++){
            res[i] = alpha2[res[i]-'a'];
        }
        
        cout << res << endl;
        
        
        
    }
    return 0;
}
