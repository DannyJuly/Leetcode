#include <iostream>


using namespace std;

int main(){
    int n;
    while(cin >> n){
        int neg = 0;
        int posi = 0;
        int number = 0;
        int num;
        for(int i = 0; i < n; i++){
            cin >> num;
            if(num < 0)
                neg++;
            else if(num > 0){
                posi += num;
                number++;
            }
                
        }
        
        double ans = double(posi) / number;
        cout.precision(1);
        cout << neg << " ";
        cout << fixed  << ans <<endl;
        //cout << ans;
    }
}
