#include <iostream>
#include <string>
#include <algorithm>
int main(){
    using namespace std;
    string str;
    while(getline(cin,str)){
        reverse(str.begin(),str.end());
        cout << str << endl;
    }
}
