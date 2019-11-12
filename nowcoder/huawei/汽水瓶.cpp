#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n && n != 0){
        int res;
        int ans = 0;
        while(n >= 3){
            ans += n / 3;
            res = n % 3;
            n = res + n / 3;
        }
        if(n == 2)
            ans++;
        cout << ans << endl;
    }
}