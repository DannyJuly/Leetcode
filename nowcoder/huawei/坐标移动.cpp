#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
int main(){
    using namespace std;
    string str;
    while(getline(cin,str)){
        stringstream ss(str);
        vector<string> vec;
        int x = 0,  y = 0;
        char ch;
        int num = 0;
        while(getline(ss,str,';'))
            vec.push_back(str);
        //cout << vec[1] <<" " <<vec[2];
        for(int i = 0; i < vec.size(); i++){
            bool flag = 0;
            //int num = stoi(vec[i].substr(1),nullptr);
            if(vec[i].size() > 1 && vec[i].size() <=3){
                ch = vec[i][0];
                num = 0;
                for(int j = 1; j <=vec[i].size()-1 ; j++){
                    if(isdigit(vec[i][j]))
                        num = num * 10 + vec[i][j] - '0';
                    else{
                        flag = 1;
                        break;
                    }
                        
                }
                if(flag == 0){
                    switch(ch){
                    case 'A': x -= num;
                        break;
                    case 'S': y -= num;
                        break;
                    case 'D': x += num;
                        break;
                    case 'W': y += num;
                        break;
                    }
                }
                
            }
                
            
        }
        cout << x <<","<<y <<endl;
            
    }
}

