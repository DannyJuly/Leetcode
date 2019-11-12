#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Erecord{
    string name;
    int line;
    int count=1;
    Erecord(string & file, int li): name(file),line(li){
        count = 1;
    }
    
    bool operator==(const Erecord & a){
        return (this->line==a.line && this->name==a.name);
    }
};

string myFilename(const Erecord & err){
    string str=err.name;
    if(str.size()>16)
        str = str.substr(str.size()-16);
    return str;
}
int main(){
    
    string filename;
    int line;
    vector<Erecord> vec;
    while(cin>>filename>>line){
        filename = filename.substr(filename.find_last_of('\\')+1);
        Erecord tmp(filename,line);
        auto pos = find(vec.begin(),vec.end(),tmp);
        if( pos == vec.end())
            vec.push_back(tmp);
        else{
            pos->count++;
        }
    }
    int count = 0;
    for(auto i : vec){
        if(count+8 >= vec.size())
            cout << myFilename(i) << " " << i.line<<" "<<i.count << endl;
        count++;
    }


}
