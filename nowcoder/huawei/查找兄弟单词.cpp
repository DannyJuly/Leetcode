#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkBro(string str1, string str2){
    sort(str2.begin(),str2.end());
    sort(str1.begin(),str1.end());
    if(str1 == str2)
        return 1;
    else
        return 0;
}
int judge(string findString,string v) 
{ 
    sort(findString.begin(),findString.end()); 
    sort(v.begin(),v.end()); 
    if(findString==v) 
        return 1; 
    else 
        return 0; 
} 
int main(){
    int num;
    int seq; 
    vector<string> words; 
    vector<string> bother; 
    string sch; 
    string temp; 
    while(cin >> num){
        vector<string> vec;
        string word;
        for(int i = 0; i < num; i++){
            cin >> word;
            vec.push_back(word);
        }
        cin >> sch >> seq;
        vector<string> bro;
        //string sorted_sch(sch);
        //sort(sorted_sch.begin(), sorted_sch.end());
        
        for(int i=0; i<num; i++) {
            if(sch != vec[i] && judge(sch, vec[i]))
                bro.push_back(vec[i]);
        }
        sort(bro.begin(), bro.end());
        cout << bro.size() << endl;
        if(seq <= bro.size())
            cout<<bro[seq-1] <<endl;
        
    }
    return 0;
}
