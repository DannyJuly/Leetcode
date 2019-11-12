#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int count=0;

bool getSub(int det, vector<int> & vec,vector<int> & visited){
    if(det == 0)
        return true;
    else{
        for(int  i= 0; i < vec.size(); i++){
            if(visited[i] == 0){
                visited[i] = 1;
                if(getSub(det - vec[i], vec, visited))
                    return true;
                visited[i] = 0;
            }
        }
    }
    return false;

        
            
        
    
}


int main() {
    int num;
    while(cin >> num){
        vector<int> vec;
        vector<int> three;
        vector<int> five;
        int n;
        int total=0;
        for(int i = 0; i < num; i++){
            cin >> n;
            total += n;
            if(n % 5 == 0)
                five.push_back(n);
            else if(n % 3==0)
                three.push_back(n);
            else
                vec.push_back(n);
        }

        if(total % 2 == 1 || total % 2 == -1)
            cout << "false" << endl;
        else{
            vector<int> visited(vec.size(),0);
            int fivesum = std::accumulate(five.begin(),five.end(),0);
            int det = total/2 - fivesum;
            if(getSub(det,vec,visited))
                cout << "true" << endl;
            else
            {
                cout << "false" << endl;
            }
            
        }
        

    }
}