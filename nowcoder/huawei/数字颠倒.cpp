#include <iostream>
#include <string>
#include <algorithm>
int main(){
    using namespace std;
    /*string str;
    while(getline(cin,str)){
        reverse(str.begin(),str.end());
        cout << str << endl;
    }*/
    int input;
    while(cin >> input){
        int sum = 0;
        string in=to_string(input);
        while(input > 0){
            sum =sum * 10 + input % 10;
            input /= 10;
        }
        
        string out=to_string(sum);
        string zero(int(in.size()-out.size()),'0');
     
        cout<<zero << sum;
    }
    
}
