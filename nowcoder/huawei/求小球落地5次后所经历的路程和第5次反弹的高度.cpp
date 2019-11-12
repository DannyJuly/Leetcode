#include <iostream>

using namespace std;



int main(){
    int high;
    while(cin >> high){
        double hi = double(high);
        double height = -hi;
        double lastheight;
        for(int i = 0 ; i < 5; i++){
            height += 2 * hi;
            hi /= 2;
        }
        cout << height << endl;
        cout << hi << endl;
    }
}
