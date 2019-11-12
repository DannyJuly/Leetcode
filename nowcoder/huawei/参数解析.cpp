#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        int sum=0;
        vector<string> res;
        for(int i = 0; i < str.size(); i++){
            if(str[i] != ' ' && str[i] !='"'){
                int k = i+1;
                while(str[k] != ' '&& k<str.size())
                    k++;
                res.push_back(str.substr(i,k-i));
                i = k;
                sum++;
            }
            else if(str[i]=='"'){
                int k = i+1;
                while(str[k] != '"'&& k<str.size()){
                    k++;
                }
                res.push_back(str.substr(i+1,k-i-1));
                i = k+1;
                sum++;
            }
        }
        cout << sum << endl;
        for(auto i:res){
            cout << i << endl;
        }
    }
}
