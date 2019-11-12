#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){

        int cnt = 0;
        for( int i = 2; i <=n; i++){
            int k = i / 2;
            int sum=0;
            for(int j=1; j <= k; j++){
                sum += i%j==0 ? j : 0;
            }
            if(sum == i)
                cnt++;
        }
        cout << cnt << endl;
    }
}
