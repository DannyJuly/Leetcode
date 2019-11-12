#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        int count=0;
        vector<string> ans;
        int max=0;
        for(int i=0; i < str.size(); i++){
            if(isdigit(str[i])){
                while(isdigit(str[i])){
                    count++;
                    i++;
                }
                i--;
            }
            else
            {
                count = 0;
            }
            
            if(count > max){
                ans.clear();
                max = count;
                ans.push_back(str.substr(i-count+1,count));
            }
            else if(count == max)
                ans.push_back(str.substr(i-count+1,count));
        }
        for(auto s : ans){
            cout << s ;
        }
        cout << ","<<ans[0].size() <<endl;
    }
       
}
