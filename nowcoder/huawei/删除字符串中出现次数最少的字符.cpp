#include <iostream>
#include <string>
#include <vector>

int main(){
    using namespace std;
    string str;
    while(getline(cin,str)){
        int nu[26] = {0};
        vector<char> vec;
        for(auto i : str)
            nu[i-'a']++;
        //find minimun
        int min = 1;
        for(auto i : nu){
            if(i > 0 && i < min)
                min = i;
        }
        for(auto i : str){
            if(nu[i-'a'] != min)
                cout << i;
        }
        cout << endl;
        
    }
}
