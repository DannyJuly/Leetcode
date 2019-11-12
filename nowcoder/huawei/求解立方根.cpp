#include <iostream>

using namespace std;
double abs(double n){
    return n>0?n:-n;
}
 
int main(){
    double num;
    while(cin >> num){
        if(num < 0)
            num = -num;
        double x;
        for(x = 1.0; abs(x*x*x - num) >1e-7; x = 2*x/3 +num/(3*x*x));
        //2/3*x不行，2/3为整数
        cout.precision(1);
        cout << fixed << x << endl;
        
        /*
        for(i = 0; i < int(num);i++){
            if(i*i*i <= num && (i+1)*(i+1)*(i+1) > num)
                break;
        }
        cout.precision(1);
        double ans;
        for(int j = 0;j < 10; j++){
            ans = i + 0.1*j;
            if(ans*ans*ans <= num && (ans+0.1)*(ans+0.1)*(ans+0.1) > num){
                if(num-ans*ans*ans > (ans+0.1)*(ans+0.1)*(ans+0.1)-num)
                    cout << fixed << ans+0.1  << endl;
                else
                    cout << fixed << ans<< endl;
                break;
            }
                
        }*/
    }
}