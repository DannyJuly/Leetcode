#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    int n;
    while(cin >> n >> str){
        int start = 1, end = 4;
        int cur = 1;
        if(n < 4)
            end = n;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'U'){
                if(start == cur){
                   if(start == 1){
                         if(n < 4){
                           start = 1;
                        }
                        else
                            start = n - 3;
                        end = n;
                        cur = n;
                   } 
                   else{
                       start--;
                       cur--;
                       end--;
                   }
                }
                else{
                    cur--;
                }
            }
            else if(str[i]=='D'){
                if(end == cur){
                    if(end == n){
                        if(n < 4)
                            end = n;
                        else
                            end = 4;
                        start = 1;
                        cur = 1;
                    }
                    else{
                        end++;
                        start++;
                        cur++;
                    }
                }
                else{
                    cur++;
                }
            }
        }

        for(int i = start; i <= end; i++){
            cout <<i << " ";
        }
        cout << endl;
        cout << cur << endl;
            
    }
}
