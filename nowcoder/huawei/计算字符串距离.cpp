#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str1,str2;
    while(cin >> str1 >> str2){
        int i = int(str1.size());
        int j = (int)str2.size();
        vector<vector<int> > v(i+1,vector<int>(j+1));
        v[0][0] = 0;
        for(int m = 1; m <= i; m++)
            v[m][0] = m;
        for(int m = 1; m <= j; m++)
            v[0][m] = m;
        for(int m = 1; m <= i; m++)
            for(int n = 1; n <= j; n++){
                int del = v[m-1][n]+1;
                int add = v[m][n-1]+1;
                int equ = v[m-1][n-1];
                if(str1[m-1] != str2[n-1])
                    equ++;
                v[m][n] = min(min(del,add),equ);
            }
        cout << v[i][j] << endl;
    }
        
}
