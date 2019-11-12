#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const char& ch1, const char& ch2){
    return ch1 < ch2;
}

int main(){
    string str;
    while(cin >> str){
        sort(str.begin(),str.end(),cmp);
        cout<<str << endl;
    }
}
