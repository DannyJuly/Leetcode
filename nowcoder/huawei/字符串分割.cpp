#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector<string> vec(n);
        for(auto &str: vec){
            cin >> str;
        }
        for(int i=0; i < n; i++){
            int k = vec[i].size() / 8;
            int r = vec[i].size() % 8;
            if(r!=0)
                vec[i].insert(k*8+r,(8-r),'0');
            else
                k--;
            for(int j=0; j <= k; j++)
                cout << vec[i].substr(j*8,8) << endl;
        }
    }
}
