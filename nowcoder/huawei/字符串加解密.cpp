#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string encrypt;
    string decrypt;
    while(cin >> encrypt >> decrypt){
        string encrypted;
        //encrypt
        for(int i = 0 ; i < encrypt.size(); i++){
            if(isupper(encrypt[i])){
                int t = encrypt[i] - 'A' + 1;
                encrypt[i] = 'a' + t % 26;
            }
            else if(islower(encrypt[i])){
                int t = encrypt[i] - 'a' + 1;
                encrypt[i] = 'A' + t % 26;
            }
            else if(isdigit(encrypt[i])){
                int t = encrypt[i] - '0' + 1;
                encrypt[i] = '0' + t % 10;
            }
            else
                continue;
        }
        //decrypt
        for(int i = 0 ; i < decrypt.size(); i++){
            if(isupper(decrypt[i])){
                int t = 'Z'-decrypt[i]+1;
                decrypt[i] = 'z' - t % 26;
            }
            else if(islower(decrypt[i])){
                int t = 'z'-  decrypt[i]  + 1;
                decrypt[i] = 'Z' - t % 26;
            }
            else if(isdigit(decrypt[i])){
                int t =  '9' - decrypt[i] + 1;
                decrypt[i] = '9' - t % 10;
            }
            else
                continue;
        }
        cout << encrypt <<endl << decrypt << endl;
        
    }
}
