#include <iostream>
#include <string>
#include <cctype>

int main(){
    using namespace std;
    string str;
    while(getline(cin,str)){
        //1
        if(str.size() <= 8){
            cout << "NG" <<endl;
            continue;
        }
        //2
        int a[4] = {0};
        for(int i = 0; i < str.size(); i++){
            if(isdigit(str[i]))
                a[0] = 1;
            else if(isupper(str[i]))
                a[1] = 1;
            else if(islower(str[i]))
                a[2] = 1;
            else
                a[3] = 1;
        }
        int sum = 0;
        for(int i : a){
            sum += i;
        }
        if(sum < 3){
            //cout << 1;
            cout << "NG" <<endl;
            continue;
        }
        //3
        bool flag = 0;
        for(int i = 0; i < str.size() - 6; i++){
            string rest = str.substr(i+3);
            string sub = str.substr(i,3);
            if(rest.find(sub) != string::npos){
                cout << "NG" << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            continue;
        else
            cout << "OK" << endl;
            
        
    }
}
