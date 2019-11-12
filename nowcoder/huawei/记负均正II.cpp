#include <iostream>

using namespace std;

int main(){
    int in;
    int nega=0;
    int posi=0;
    int posicnt=0;
    while(cin>>in){
        
        if(in < 0)
            nega++;
        if(in > 0){
            posi+= in;
            posicnt++;
        }
    }
    cout << nega << endl;
    double ans = double(posi) / posicnt;
    cout.precision(1);
    cout << fixed << ans << endl;
        
    
}
