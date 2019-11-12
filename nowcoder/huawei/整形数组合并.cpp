#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void bubble(int a[],int n){
    for(int i = n; i > 0; i--){
        for(int j = 0; j < n-1; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}



int main(){
    int n;
    while(cin >> n){
        int* a1 = new int[n];
        for(int i = 0; i < n; i++)
            cin >> a1[i];
        int m;
       // cout << a1[0]<<a1[1]<<a1[2];
        cin>>m;
        int* a2 = new int[m];
        for(int i = 0; i < m; i++)
            cin >> a2[i];
        int i = 0,j = 0;
        bubble(a1,n);
        bubble(a2,m);
       // cout << a1[0]<<a1[1]<<a1[2];
        while(i < n || j < m){
            while( i < (n-1) && a1[i] == a1[i+1] )
                i++;
            while(j < (m-1) && a2[j] == a2[j+1])
                j++;
            if(i==n){
                cout << a2[j];
                j++;
            }
            else if(j==m){
                cout << a1[i];
                i++;
            }
            else if(a1[i] < a2[j]){
                cout << a1[i];
                i++;
            }
            else if(a1[i]==a2[j]){
                cout<<a1[i];
                i++;
                j++;
            }
            else{
                cout << a2[j];
                j++;
            }
                
        }
        cout<<endl;
    }
}
