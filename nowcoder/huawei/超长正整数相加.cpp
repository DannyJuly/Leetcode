#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1,str2;
    while(cin >> str1 >> str2){
        while(str1.size() > str2.size()){
            str2 = '0'+str2;
        }
        while(str1.size() < str2.size()){
            str1 = '0'+str1;
        }
        string str;
        int ind = 0;
        for(int i = str1.size()-1; i >=0 ; i--){
            int num = str1[i]+str2[i]-'0'-'0' + ind;
            if(num >= 10){
                ind = 1;
                num -= 10;
                str = char(num+'0') + str;
            }
            else{
                ind = 0;
                str = char(num+'0') + str;
            }
        }
        if(ind == 1){
            str = '1' + str;
        }
        cout << str << endl;
    }
}
