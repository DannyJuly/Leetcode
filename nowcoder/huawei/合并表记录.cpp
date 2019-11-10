#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<int,int> & a, const std::pair<int,int> &b){ //compare funcion for sort
    return a.first < b.first;
}

struct greate  //just for test
{
  bool operator()(const int& x, const int& y) const
  {return x>y;}
};


int main(){
    using namespace std;
    int num;
    
    while(cin >> num){
        int idx, val;
        map<int,int> m;
        map<int,int>::iterator it;
        for(int i = 0; i < num; i++){
            cin >> idx >> val;
            if(m.count(idx) > 0){
                m[idx] += val;
            }
            else
                m.insert(make_pair(idx,val));
        }
        //vector<pair<int,int> > vec(m.begin(),m.end());
        //sort(vec.begin(),vec.end(), cmp);
        for(it = m.begin(); it != m.end(); it++)
            cout << it->first << " " << it->second << endl;
    }
}
