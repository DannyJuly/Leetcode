#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n;
    while(cin >> str >> n){
        int ind = 0;
        string sub;
        if( n >= str.size())
            cout << str << endl;
        else{
            int ratio = 0;
            
            for(int i = 0; i < str.size()-n; i++){
                int g = 0;
                for(int j = i; j < i+n; j++){
                    if(str[j] == 'G' || str[j] == 'C')
                        g++;
                }
                if(g > ratio){
                    ind = i;
                    ratio = g;
                }
                    
            }
            cout << str.substr(ind,n) << endl;
        }
        
            
    }
}
