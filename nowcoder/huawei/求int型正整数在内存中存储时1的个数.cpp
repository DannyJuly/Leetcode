
#include<iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a){
        int count = 0;
        while(a!=0){
            a &= a-1; //不断清除最右边的1
            count++;
        }
        cout << count;
    }
    return 0;
}
