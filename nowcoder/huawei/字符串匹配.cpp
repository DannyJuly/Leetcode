#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    string str1;
    string str2;
    while(cin>>str1>>str2){
        int a[26]={0};
        int b[26]={0};
        for(auto i : str1)
            a[i-'a']++;
        for(auto j : str2)
            b[j-'a']++;
        for(int i = 0 ;i < 26; i++){
            if(a[i]!=0 && b[i]==0){
                cout << "false" << endl;
                break;
            }
                
            else if(i == 25)
                cout<<"true"<<endl;
        }
        
    }
        
}
