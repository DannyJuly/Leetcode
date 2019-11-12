#include <iostream>

using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        int dot = m * n;
        while(m%n){
            int tmp = m%n;
            m = n;
            n = tmp;
        }
        int ans = dot / n;
        cout << ans << endl;
    }
}
