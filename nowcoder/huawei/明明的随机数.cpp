#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> vec(n);
        int num;
        for(auto &i : vec)
            cin >> i;
        sort(vec.begin(),vec.end());
        cout << vec.front() << endl;
        for(int i = 1; i < vec.size(); i++){
            while(i < vec.size() && vec[i] == vec[i-1])
                i++;
            if(i != vec.size())
                cout << vec[i] <<endl;
        }
        
    }
}
