#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        //len = str.size();
        int a[26]={0};
        for (int i = 0; i < str.size(); i++)
            a[str[i] - 'a']++;
        //cout << a[1];
        for(int i=0; i< str.size();i++){
            if(a[str[i]-'a'] == 1){
                cout << str[i]<<endl;
                break;
            }
                
            else if(i==str.size()-1){
                cout << -1  << endl;
            }
        }
    }
}
