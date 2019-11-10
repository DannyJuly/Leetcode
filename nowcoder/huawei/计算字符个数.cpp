#include <iostream>
#include <string>
#include <cctype>
int main(){
    using namespace std;
    string str;
    getline(cin,str);
    char ch;
    cin >> ch;
    int count=0;
    for(int i = 0; i < str.size(); i++){
        if(tolower(str[i]) == tolower(ch))
            count++;
    }
    cout << count;
}
