#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str1,str2;
    //string s = "assd";
   // cout << s.substr(0,0);
    while(cin >> str1 >> str2){
        if(str1.size() > str2.size()){
            string tmp(str1);
            str1 = str2;
            str2 = tmp;
        }
        /*bool flag=false;
        for(int i = str1.size(); i > 0; i--){
            for(int j = 0; j <= str1.size()-i; j++){
                if(str2.find(str1.substr(j,i))!=string::npos){
                    cout << str1.substr(j,i) << endl;
                    flag = true;
                    break;
                }     
            }
            if(flag)
                break;
        }*/
        int max=0;
        int ind=0;
        vector<vector<int> > dp(str1.size()+1,vector<int>(str2.size()+1,0));
       // vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        ///int i;
        for(int i = 1; i <= str1.size(); i++)
            for(int j = 1; j <= str2.size(); j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = 0;
                if(dp[i][j] > max){
                    max = dp[i][j];
                    ind = i - max;
                }
            }
        cout << str1.substr(ind,max) << endl;
        
        
    }

}
