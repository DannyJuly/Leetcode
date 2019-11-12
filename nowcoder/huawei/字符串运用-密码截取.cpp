#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        
        int max = 1;
        int len = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == str[i+1]){
                len = 2;
                for(int j = i - 1, k = i + 2; j >=0, k < str.size(); j--, k++){
                    if(str[j] == str[k])
                        len += 2;
                    else{
                        if(len > max)
                            max = len;
                        break;
                    }
                }
            }
            else if(str[i] == str[i+2] && i+2 < str.size()){
                len = 3;
                for(int j = i - 1, k = i + 3; j >=0, k < str.size(); j--, k++){
                    if(str[j] == str[k])
                        len += 2;
                    else{
                        if(len > max)
                            max = len;
                        break;
                    }
                }
            }
        }
        cout << max <<endl;
    }
}
