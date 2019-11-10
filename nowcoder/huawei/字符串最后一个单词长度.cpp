#include <iostream>
#include <string>

int main(){
    using namespace std;
    string str;
    getline(cin,str);
    int res = 0;
    int len = str.size()-1;
    while(str[len] != ' ' && len != 0){
        res++;
        len--;
    }
    if(len == 0)
        res++;
    cout << res;
}
