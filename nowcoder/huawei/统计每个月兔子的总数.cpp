#include <iostream>
#include <vector>
using namespace std;

int getTotalCount(int month, vector<int>& memo){
    if(memo[month] != 0)
        return memo[month];
    else if(month <= 2)
        return 1;
    memo[month] = getTotalCount(month - 1,memo) + getTotalCount(month - 2,memo);
    return memo[month];
}
/*
int main(){
    int n;
    while(cin >> n){
        vector<int> memo(n+1);
        int res = getTotalCount(n, memo);
        cout << res << endl;
    }
}
*/
 
int main(){
    int m;
    while(cin>>m){
        int a=1,b=0,c=0;//a:一个月兔子数，b：两个月兔子数，c：三个月兔子个数
        while(--m){//每过一个月兔子数变化
            c+=b;
            b=a;
            a=c;
        }
        cout<<a+b+c<<endl;
    }
}