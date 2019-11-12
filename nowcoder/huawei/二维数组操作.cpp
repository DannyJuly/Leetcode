#include <iostream>

using namespace std;

int main(){
    int m,n;
    while(cin>>m>>n){
        int row,col;
        cout << 0 <<endl;
        cin >> row >>col;
        if(row >= m || col >= n)
            cout << -1 <<endl;
        else
            cout << 0 <<endl;
        cin >> row >>col;
        if(row >= m || col >= n)
            cout << -1 <<endl;
        else
            cout << 0 <<endl;
        cin >>row;
        if(row >= m)
            cout << -1 <<endl;
        else{
            cout << 0 <<endl;
            m++;
        }
            
        cin >> col;
        if(col >= n)
            cout << -1 <<endl;
        else{
            cout << 0 <<endl;
            n++;
        }
        cin >> row >> col;
        if(row < m && col < n){
            cout << 0 <<endl;
        }
        else{
            cout << -1 << endl;
        }
        
    }
}
