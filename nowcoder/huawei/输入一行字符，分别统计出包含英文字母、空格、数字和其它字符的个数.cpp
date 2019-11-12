#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        int alpha=0,space=0,digit=0,other=0;
        for(int i = 0; i < str.size(); i++){
            if(isalpha(str[i]))
                alpha++;
            else if(str[i] == ' ')
                space++;
            else if(isdigit(str[i]))
                digit++;
            else
                other++;
        }
        cout << alpha <<endl;
        cout << space << endl;
        cout << digit << endl;
        cout << other << endl;
    }
}
