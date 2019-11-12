#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string helper1 = "0123456789abcdefABCDEF";
const string helper2 = "084C2A6E195D3B7F5D3B7F";

int main(){
    string str1,str2;
    while(cin >> str1 >> str2){
        string str = str1 + str2;
        string odd;
        string even;
        string output;
        for(int i = 0; i < str.size(); i++){
            if(i % 2 == 0)
                even.push_back(str[i]);
            else
                odd.push_back(str[i]);
        }
        
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        for(int i = 0; i < str.size(); i++){
            if(i % 2 == 0)
                str[i] = even[i/2];
            else
                str[i] = odd[i/2];
        }
        
        for(int i = 0; i < str.size(); i++){
            int pos = helper1.find(str[i]);
            if(pos != string::npos)
                str[i] = helper2[pos];
        }
        
        cout << str << endl;
    }
}
