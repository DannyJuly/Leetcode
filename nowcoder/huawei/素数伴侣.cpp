//https://www.cnblogs.com/CZiFan/p/9708746.html
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
vector<bool> used;
vector<int> hasodd;
vector<vector<int> > line;

bool checkPrime(int x, int y){
    int sum = x + y;
    if(sum == 1)
        return false;
    if(sum == 2)
        return true;
    if(sum % 2 == 0)
        return false;
    for(int i = 2; i <= sqrt(sum); i++){
        if( sum % i == 0)
            return false;
    }
    return true;
}

bool find(int x){
    for(int i = 0; i < line[0].size(); i++){
        if(line[x][i] == 1 && !used[i]){
            used[i] = true;
            if(hasodd[i] == -1 || find(hasodd[i])){
                hasodd[i] = x;
                return true;
            }
        }
    }
    return false;
}


int main(){
    int n;
    int a[3] = {1,2,3};
   // cout << sizeof(int) ;
    //
    //cout << a[2];
    vector<vector<int>> aa;
    //aa.resize(3,vector<int>(4,2));
    //aa.assign(aa.size(),0);
    //cout << sizeof(aa);
    //memset(aa,0,sizeof(aa));
    //cout << aa[2][2];
    while(cin >> n){
        vector<int> odd;
        vector<int> even;
        int num;
        for(int i = 0; i < n ; i++){
            cin >> num;
            if(num % 2 == 0)
                even.push_back(num);
            else
                odd.push_back(num);
        }
        used.clear();
        used.resize(odd.size(),false);
        //vector<bool> used(odd.size(),false);
        hasodd.clear();
        hasodd.resize(odd.size(),-1);
        //vector<int> hasodd(odd.size(),-1);
        line.clear();
        line.resize(even.size(),vector<int>(odd.size(),0));
        //vector<vector<int> > line(even.size(),vector<int>(odd.size(),0));
        for(int i = 0; i < even.size(); i++){
            for(int j = 0; j < odd.size(); j++){
                if(checkPrime(even[i],odd[j]))
                    line[i][j]=1;
            }
        }

        int res = 0;
        for(int i = 0; i < even.size(); i++){
            used.assign(used.size(),false);
            if(find(i))
                res++;
        }
        
        cout << res << endl;
        
    }
}
