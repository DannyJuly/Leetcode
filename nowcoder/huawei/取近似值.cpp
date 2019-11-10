#include <iostream>

int main(){
    
    using namespace std;
    float input;
    while(cin >> input)
        cout << static_cast<int>(input+0.5)<<endl;
    
}
