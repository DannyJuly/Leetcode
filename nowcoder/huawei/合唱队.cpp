#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int count=0;

void getSub(vector<int> & vec, vector<int> & posi){
    vector<int> tail(1,vec[0]);
    vector<int>::iterator ind;
    for(int i= 1; i < vec.size(); i++){
        ind = lower_bound(tail.begin(),tail.end(),vec[i]);
        if(ind != tail.end()){
            *ind = vec[i];
            posi[i] = int(ind - tail.begin())+1;
        }   
        else{
            tail.push_back(vec[i]);
            posi[i] = tail.size();
        }
            
        
    }
}


int main() {
    int num;
    while(cin >> num){
        vector<int> vec(num,0);
        vector<int> posi(num,1);
        vector<int> nega(num,1);
        for(auto & i : vec)
            cin >> i;
        vector<int> reversed(vec);
        reverse(reversed.begin(),reversed.end());
        getSub(vec,posi);
        getSub(reversed,nega); 
        reverse(nega.begin(),nega.end());
        int ans=1;
        for(int i=0; i < num; i++){
            if(posi[i]+nega[i]>ans)
                ans = posi[i]+nega[i];
        }

        cout << num-ans+1 << endl;

    }
}
