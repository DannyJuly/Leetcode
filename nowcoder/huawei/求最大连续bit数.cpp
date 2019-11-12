#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int count=0;
        while(n){
            n &= (n<<1);
            count++;
        }
        cout << count << endl;
        
        /*
        std::bitset<32> mybits(n);     // mybits: 0000
       // mybits.set();              // mybits: 1111

        std::string s =
        mybits.to_string();

       // std::cout << "mystring: " << s << '\n';
        int max=0;
        for(int i = 0; i < s.size(); i++){
            //cout << i;
            int count = 0;
            while(s[i]=='1' && i < s.size()){
                i++;
                count++;
            }
            if(count > max){
                max = count;
            }
        }
        cout << max <<endl;*/
    }
}