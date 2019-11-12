#include <iostream>
#include <algorithm>

int main(){
    using namespace std;
    int N,m;
    int weight[60][3] = {0};
    int value[60][3] = {0};
    
    while(cin >> N >> m){
        int dp[3201] = {0};
        N /= 10;
        int v,p,q;
        for(int i = 1; i <= m; i++){
            cin >> v >> p >> q;
            p = p * v;
            v /= 10;
            if(q == 0){
                weight[i][q] = v;
                value[i][q] = p;
          
            }
            else if(weight[q][1] == 0){
                weight[q][1] = v;
                value[q][1] = p;
            }
            else{
                weight[q][2] = v;
                value[q][2] = p;
            }
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = N; j > 0; j--){
                //dp[i][j] = dp[i-1][j];
                if(weight[i][0]<=j)
                    dp[j] = max(dp[j],dp[j-weight[i][0]]+value[i][0]);
                if(weight[i][0]+weight[i][1]<=j)
                    dp[j] = max(dp[j],dp[j-weight[i][0]-weight[i][1]]+value[i][0]+value[i][1]);
                if(weight[i][0]+weight[i][2]<=j)
                   dp[j] = max(dp[j], dp[j-weight[i][0]-weight[i][2]]+value[i][0]+value[i][2]);
                if(weight[i][0]+weight[i][1]+weight[i][2]<=j)
                    dp[j] = max(dp[j],dp[j-weight[i][0]-weight[i][1]-weight[i][2]]+value[i][0]+value[i][1]+value[i][2]);
                
            }
        }
        cout << dp[N];
        
    }
    return 0;
}
