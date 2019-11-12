#include <iostream>
#include <vector>
#include <algorithm>
#include <priority_queue>
using namespace std;

int main(){
    int m,n;
    while(cin >> m >> n){
        vector<int> vec(m);
        for(int i = 0; i < m; i++){
            cin >> vec[i];
        }
        priority_queue<int> pq;
        sort(vec.begin(),vec.end());
        for(auto it = vec.begin(); it != vec.begin()+n; it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}
