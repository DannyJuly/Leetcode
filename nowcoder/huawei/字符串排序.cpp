#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        vector<char> vec;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < str.size(); j++){
                if(str[j] == 'a'+i || str[j] == 'A' + i)
                    vec.push_back(str[j]);
            }
        }
        
        int k = 0;
        for(int i = 0; i < str.size(); i++){
            if(isalpha(str[i]))
                str[i] = vec[k++];
        }
        
        cout << str << endl;
        
    }

    
}
