#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

int main(){
    string str;
    vector<string> vec;
    while(getline(cin,str)){
        vec.clear();
        for(int i = 0; i < str.size(); i++){
            if(!isalpha(str[i]))
                str[i] = ' ';
        }
        stringstream ss(str);
        string substr;
        while(ss >> substr){
            vec.push_back(substr);
        }
        string output;
        for(auto it=vec.rbegin(); it != vec.rend(); it++){
            output += *it + " ";
        }
        output.erase(output.end()-1);
        cout << output << endl;
    }
}
