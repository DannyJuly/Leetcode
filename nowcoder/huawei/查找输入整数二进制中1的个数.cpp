#include <iostream>
#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        /*int sum = 0;
        for(int i=0; i < 32; i++){
            if(n & 1){
                sum++;
            }
            n = n >> 1;
        }
        
        cout << sum << endl;*/
        bitset<8*sizeof(int)> bs(n);
        cout << bs.count() << endl;
    }
}
