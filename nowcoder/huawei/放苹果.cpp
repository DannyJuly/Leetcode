#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int count(int m,int n){
    if(m==0 || m == 1 || n== 1)
        return 1;
    if(m < 1)
        return 0;
    return count(m-n,n) + count(m,n-1); 
}

int main() {
    int m,n;
    while(cin >> m >> n){
        cout << count(m,n) << endl;
    }
}
