#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string str;
    string cmd[6] = {"reset",       "reset board", "board add",     "board delet",      "reboot backplane", "backplane abort" };
    string res[7] = {"reset what",  "board fault", "where to add",  "no board at all",  "impossible",       "install first",    "unkown command" };
    while(getline(cin,str)){
        stringstream ss(str);
        string str1,str2;
        ss >> str1 >> str2;
        int ind;
        if(str2.empty()){
            if(cmd[0].find(str1) == 0)
                ind = 0;
            else
                ind = 6;
        }
        else{
            int k=0;
            for(int i = 1; i < 6;i++){
                stringstream s(cmd[i]);
                string c1,c2;
                s >> c1 >> c2;
                if(c1.find(str1) == 0 && c2.find(str2) ==0){
                    k++;
                    ind = i;
                }
            }
            if(k!=1)
                ind = 6;
        }
        cout << res[ind] << endl;
    }
}
