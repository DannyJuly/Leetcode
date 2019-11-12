#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> m(n);
        vector<int> x(n);
        for(int i = 0; i < n; i++){
            cin >> m[i];
        }
        for(int i = 0; i < n; i++){
            cin >> x[i];
            //cout << "a";
        }
        
            

        vector<int> weight;
        int neweight;
        for(int i = 0; i <= x[0]; i++){
            weight.push_back(i*m[0]);
        }
        //cout << weight.size()<< "size";
        for(int i = 1; i < n; i++){
            int size = weight.size();
            for(int j = 1; j <= x[i]; j++){
                for(int k = 0; k < size; k++){
                    neweight = weight[k] + j * m[i];
                    if(find(weight.begin(),weight.end(),neweight) == weight.end())
                        weight.push_back(neweight);
                }
            }
            
        }
 
        cout << weight.size() << endl;
    }
}
