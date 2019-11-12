#include <string>
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


int main(){
    string s1,s2;
    while(cin >>s1 >>s2){
        string s3;
        if((s1[0] =='-' && s2[0]=='-') || (isdigit(s1[0]) && isdigit(s2[0]))){
            bool flag = true;
            if(s1[0] == '-'){
                s1 = s1.substr(1);
                s2 = s2.substr(1);
                flag =false;
            }
            while(s1.size() < s2.size())
                s1.insert(0,1,'0');
            while(s1.size() > s2.size())
                s2.insert(0,1,'0');
            int m = s1.size()-1;
            int ind = 0;
            //cout << s1 << " "<< s2 << endl;
            while( m >= 0){
                int num = s1[m] - '0' +s2[m] - '0' +ind;
                if(num >= 10){
                    ind = 1;
                    num -= 10;
                } 
                else
                    ind = 0;
                s3 = char(num+'0') + s3;
                m--;
            }
            if(ind == 1)
                s3 = '1'+s3;
            if(flag == false)
                s3 = '-' + s3;
                
        }
        else{
            if(s1[0] == '-'){
                string tmp = s1;
                s1 = s2;
                s2 = tmp.substr(1);
            }
            else
                s2 = s2.substr(1);
            while(s1.size() < s2.size())
                s1.insert(0,1,'0');
            while(s1.size() > s2.size())
                s2.insert(0,1,'0');
            bool flag = true;
            if(s1 < s2){
                string tmp = s1;
                s1 = s2;
                s2 = tmp;
                flag = false;
            }
            //cout<<s1 << " "<<s2;
            int m = s1.size()-1;
            int ind = 0;
            while( m >= 0){
                int num = s1[m] - '0' - (s2[m] - '0') +ind;
                if(num < 0){
                    num += 10;
                    ind = -1;
                }
                else
                    ind = 0;
                s3 = char(num + '0') + s3;
                m--;
            }
            for(int i = 0; i < s3.size(); i++){
                if(s3[i] != '0'){
                    s3 = s3.substr(i);
                    break;
                }
                else if(i == s3.size()-1)
                    s3 = s3[i];
            }
            if(flag == false)
                s3 = "-" + s3;
        }
        cout << s3 << endl;
    }
}
