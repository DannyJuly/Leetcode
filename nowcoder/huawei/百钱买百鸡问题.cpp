#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > ans;
bool flag = false;
void dfs(int sum,vector<int> & num){
    if(sum == 0 && num[0]+num[1]+num[2] == 100){
        ans.push_back(num);
        flag = true;
        return;
    }
    if(sum - 5 >=0 && num[0]+num[1]+num[2] < 100){
        num[0]++;
        dfs(sum-5,num);
        num[0]--;
    }
    if(sum - 3 >=0 && num[0]+num[1]+num[2] < 100){
        num[1]++;
        dfs(sum-3,num);
        num[1]--;
    }
    if(sum - 1 >=0 && num[0]+num[1]+num[2] < 100){
        num[2] += 3;
        dfs(sum-1,num);
        num[2] -= 3;
    }
           
}


int main(){
    int n;
    while(cin>>n){
        int a[3]={5,3,1};
        vector<int> num(a,a+sizeof(a)/sizeof(int) );
        dfs(100,num);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i][0] <<" "<<ans[i][1] << " "<<ans[i][2] <<endl;
        }
        /*for(int x=0; x <= 20;x++){
            for(int y=0; y <= 100-5*x; y++){
                int z = (100-5*x-3*y)*3;
                if(z + x + y == 100)
                    cout << x << " " << y << " " << z <<endl;
            }
        }*/
        
    }
}