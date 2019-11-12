#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Stu{
    string name;
    int grade;
};

bool greaterseq(const Stu & st1,const Stu & st2){
    return st1.grade < st2.grade;
}
bool lessseq(const Stu & st1,const Stu & st2){
    return st1.grade > st2.grade;
}
int main(){
    int n, type;
    while(cin >> n >> type){
        vector<Stu> stu;
        for(int i = 0; i < n; i++){
            Stu s;
            cin >> s.name >> s.grade;
            stu.push_back(s);
        }
        
        if(type == 1)
            stable_sort(stu.begin(),stu.end(),greaterseq);
        else
            stable_sort(stu.begin(),stu.end(),lessseq);
        for(auto i : stu){
            cout << i.name << " "<< i.grade << endl;
        }
    }
}
