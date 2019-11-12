#include<stdio.h>
#include<iostream>
 
using namespace std;
//数学公式直接可以推出来首项是m*m+1-m,有m项
int main(){
    int m;
    while(cin>>m){
        int s = m*m+1-m;
        cout<<s;
        for(int i=1;i<m; i++)
            cout<<'+'<<s+2*i;
        cout<<endl;
    }
    return 0;
}
