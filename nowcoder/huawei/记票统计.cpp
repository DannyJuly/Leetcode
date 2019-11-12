#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int num;
    while(cin >> num){
        map<string,int,less<string> > mymap;
        vector<string> name(num);
        vector<int> count(num,0);
        string str;
        for(int i = 0;i < num; i++){
            cin >> name[i];
        }
        cin >> num;
        int invalid = 0;
        for(int i = 0; i < num; i++){
            cin >> str;
            auto it = find(name.begin(),name.end(),str);
            if(it != name.end()){
                count[it-name.begin()]++;
            }
            else
                invalid++;
        }

        for (int i =0; i < name.size();i++)
            std::cout << name[i] << " : " << count[i]<< '\n';
        cout << "Invalid : "<<invalid<<endl;


    }
}
