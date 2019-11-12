#include <iostream>
#include <vector>

using namespace std;

void getLine(vector<int> & vec, int n){
    if(n == 1)
        return;
    else{
        vector<int> tmp = vec;
        vec.insert(vec.begin(),0);
        for(int i = 2; i < int(tmp.size()); i++)
            vec[i] = tmp[i-2]+tmp[i-1]+tmp[i];
        vec.push_back(0);
        getLine(vec,n-1);
        
    }
    
}

int main(){
    int num;
    while(cin >> num){
        vector<int> vec = {0,0,1,0,0};
        getLine(vec,num);
        int flag=0;
        for(int i = 2; i <= int(vec.size()/2); i++){
            if(vec[i] % 2==0){
                cout << i-1<< endl;
                flag=1;
                break;
            }
        }
        if(flag == 0)
            cout << -1 << endl;
    }
}
