#include <iostream>
#include <vector>

using namespace std;

int count=0;
void func(int m, int n,int goal1,int goal2){
    if(m==goal1 && n == goal2){
        count++;
        return;
    }
    if(m == goal1){
        func(m,n+1,goal1,goal2);
    }
    else if(n==goal2){
        func(m+1,n,goal1,goal2);
    }
    else{
        func(m+1,n,goal1,goal2);
        func(m,n+1,goal1,goal2);
    }
        
    
}

int main() {
    int m,n;
    while(cin>>m>>n){
        count = 0;
        func(0,0,m,n);
        cout << count << endl;
        
    }
}
