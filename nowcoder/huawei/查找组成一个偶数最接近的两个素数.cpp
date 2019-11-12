#include <iostream>
#include <cmath>


using namespace std;

bool checkPrime(int m){
    if(m==2)
        return true;
    else if(m % 2 == 0 || m<=1)
        return false;
    int k = sqrt(m);
    for(int i = 3; i <= k; i+=2){
        if(m%i==0)
            return false;
    }
    return true;
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n/2-1; i++){
            if(checkPrime(n/2-i) && checkPrime(n/2+i)){
                cout << n/2-i << endl <<n/2+i<<endl ;
                break;
            }
               
        }
    }
}
