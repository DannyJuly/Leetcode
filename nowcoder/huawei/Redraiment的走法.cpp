#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> num(n);
        vector<int> dp(n,1);
        for(auto & i : num){
            cin >> i;
        }
        int ans=0;
        for(int i = 1;i < n; i++){
            for(int j = 0; j < i; j++){
                if(num[i] > num[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(dp[i],ans);
        }
        cout << ans <<endl;
        
        
        /*
        vector<int> dp(n,1);
        vector<int> vec(1,num[0]);
        for(int i = 1; i < n; i++){
            for(int j = vec.size()-1; j >= 0; j--){
                if(num[i] > vec[j]){
                    dp[i] = j + 2;
                    break;
                }
                    
            }
            if(dp[i] > vec.size())
                vec.push_back(num[i]);
            else if(num[i] < vec[dp[i]-1])
                vec[dp[i]-1] = num[i];
        }
        cout<<vec.size()<<endl;
        */
    }
}
