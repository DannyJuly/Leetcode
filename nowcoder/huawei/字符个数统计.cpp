#include <iostream>
#include <set>
#include <string>

int main(){
    using namespace std;
    string str;
    while(getline(cin,str)){
        int a[128] = {0};
        int res = 0;
        set<char> s;
        for(int i = 0; i < str.size(); i++){
            s.insert(str[i]);
            if(str[i] >= 0 && str[i] <=127)
                a[str[i]]++;
            
        }
            
        for(int i = 0; i < 128; i++)
            if(a[i] > 0)
                res++;
        
        cout << res <<endl;

    }
}
