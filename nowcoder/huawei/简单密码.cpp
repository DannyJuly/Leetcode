#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
int main(){
    using namespace std;
    string str;
    /*unordered_map<char,int> m({{'a',2},{'b',2},{'c',2},{'d',3},{'e',3},{'f',3},{'g',4},
                              {'h',4},{'i',4},{'j',5},{'k',5},{'l',5},{'m',6},{'n',6},
                              {'o',6},{'p',7},{'q',7},{'r',7},{'s',7},{'t',8},
                              {'u',8},{'v',8},{'w',9},{'x',9},{'y',9},{'z',9},});*/
    int nu[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    
    while(cin >> str){
        for(int i = 0; i < str.size(); i++){
            if(isdigit(str[i]))
                cout << str[i];
            else if(isupper(str[i])){
                int t = str[i] - 'A' + 1;
                char ch = 'a' + t % 26;
                cout << ch;
            }
            else if(islower(str[i]))
                cout << nu[str[i]-'a'];
            else
                cout << str[i];
        }
        cout << endl;
    }
}
