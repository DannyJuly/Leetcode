#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        //int n = stoi(str,nullptr,16);
        //cout << n <<endl;
        str = str.substr(2);
        int ans = 0;
        for(int i = 0; i < str.size(); i++){
            if(isdigit(str[i]))
                ans = ans * 16 + int(str[i]-'0');
            else
                ans = ans * 16 + int(str[i]-'A') + 10 ;
        }
        cout << ans <<endl;
    }
}
