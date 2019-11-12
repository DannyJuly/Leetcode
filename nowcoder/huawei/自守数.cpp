#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int cnt = 2;
        for(int i =2; i < n; i++){
            string s1 = to_string(i);
            if(s1.back() == '1' || s1.back()== '5'||s1.back() == '6'){
                string s2 = to_string(i*i);
                if(s2.find(s1,s2.size()-s1.size()) != string::npos)
                    cnt++;
            }
        }
        cout << cnt <<endl;
    }
}
