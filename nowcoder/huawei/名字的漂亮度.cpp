#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<string> vec(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        for(int i = 0; i < n; i++){
            string str = vec[i];
            vector<int> bea;
            int a[26]={0};
            int sum = 0;
            int add = 26;
            for(int j = 0; j < str.size(); j++)
                a[str[j] - 'a']++;
            for(int k = 0; k < 26; k++){
                if(a[k]>0)
                    bea.push_back(a[k]);
            }
            sort(bea.rbegin(),bea.rend());
            for(int m = 0; m < bea.size(); m++){
                sum += bea[m]*(add--);
            }
            cout << sum <<endl;
        }
    }
}
