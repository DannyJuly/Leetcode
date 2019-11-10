#include <iostream>

int main(){
    using namespace std;
    int num;
    while(cin >> num){
        int prime = 2;
        if(num == 1)
            cout << num << " ";
        while(num >= prime){
            while(num % prime == 0){
                num = num / prime;
                cout << prime << " ";
            }
            prime++;
        }
    }
        
}
