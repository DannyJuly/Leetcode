
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> vec(4);
bool flag=false;
void dfs(int ind, double sum){
    if(ind == 4 && abs(sum -24) <= 1e-4){
        flag=true;
        return;
    }
    if(flag || ind >= 4)
        return;
    for(int i = 0; i < 4; i++){
        if(i==0)
            dfs(ind+1,sum+vec[ind]);
        if(i==1)
            dfs(ind+1,sum-vec[ind]);
        if(i==2)
            dfs(ind+1,sum*vec[ind]);
        if(i==3)
            dfs(ind+1,sum/vec[ind]);
    }
        
}

int main(){
    while(cin >> vec[0] >> vec[1] >> vec[2] >> vec[3]){
        sort(vec.begin(),vec.end());
        do{
            dfs(0,0);
        }while(next_permutation(vec.begin(),vec.end()));
        if(flag)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
