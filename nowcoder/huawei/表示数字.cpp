#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        for(int i = 0; i < str.size(); i++){
            //int k = i;
            if(isdigit(str[i]) && (i==0 || isalpha(str[i-1]))){
                str = str.substr(0,i) + '*' + str.substr(i);
                i++;
            }
            if(isdigit(str[i]) && (i==str.size()-1 || isalpha(str[i+1]))){
                str = str.substr(0,i+1) + "*" +str.substr(i+1);
                i++;
            }
            /*if(isdigit(str[i])){
                int k = i;
                while(isdigit(str[i]))
                    i++;
                str.insert(k,"*");
                str.insert(i+1,1,'*');
            }*/
        }
        cout << str <<endl;
        
    }
}
