#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        int max = 0;
        vector<vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i = 1; i <= s1.size(); i++){
            for(int j = 1; j <= s2.size(); j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j] > max){
                        max = dp[i][j];
                    }
                }
                    
                
            }
        }
        cout << max << endl;
        
        
        /*for(int i = str1.size(); i > 0 ; i--){
            for(int j = 0; j <= str1.size()-i; j++){
                if(str2.find(str1.substr(j,i)) != string::npos){
                    cout << i << endl;
                    i = 0;
                    break;
                }
                    
            }
        }*/
    }
}
