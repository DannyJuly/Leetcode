#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    string str;
    while(cin>>str){
        if(count(str.begin(),str.end(),'.') != 3)
            cout << "NO"<<endl;
        else{
            bool flag=true;
           // vector<int> res;
            string num;
            stringstream ss(str);
            while(getline(ss,num,'.')){
                if(stoi(num) <0 || stoi(num) >= 256)
                flag = false;
            }
            /*for(int i = 0; i < 4; i++){
                size_t find = str.find('.');
                res.push_back(stoi(str.substr(0,find)));
                str = str.substr(find+1);
            }
            for(int i : res){
                if( i < 0 || i >= 256)
                    flag = false;
            }*/
            if(flag)
                cout << "YES" <<endl;
            else
                cout << "NO" <<endl;
        }
    }
}
