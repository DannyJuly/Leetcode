#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool check(vector<int> &vec, vector<int> &push){
    stack<int> st;
    int pt = 0;
    for(int i = 0; i < vec.size(); i++){
        st.push(push[i]);
        while(pt < vec.size()&& !st.empty() && vec[pt] == st.top()){
            pt++;
            st.pop();        
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

vector<vector<int> > res;
vector<int> used;
void dfs(int index,int & n,vector<int> &num,vector<int> &push){
    if(index == n){
        if(check(num,push))
        {
               for(int j=0; j < n-1;j++)
                cout << num[j] << " ";
                cout << num[n-1] << endl;
            }
        return;
    }
    else{
        for(int i=1;i <= n; i++){
           // cout <<i<<" ";
            if(used[i-1] == 0){
                used[i-1]=1;
                num.push_back(i);
                dfs(index+1,n,num,push);
                num.pop_back();
                used[i-1]=0;
                
            }
        }
    }
}

void backtrack(int index,vector<int> &num,vector<int> &push){
    if(index == num.size()){
        if(check(num,push))
        {
               for(int j=0; j < num.size()-1;j++)
                cout << num[j] << " ";
                cout << num.back() << endl;
            }
        return;
    }
    else{
        for(int i = index; i < num.size(); i++){
            int tmp = num[index];
            num[index] = num[i];
            num[i] = tmp;
            backtrack(index+1,num,push);
            tmp = num[index];
            num[index] = num[i];
            num[i] = tmp;
        }
    }
}

int main(){
    int n;
   // stack<int> s;
    //s.top()
   // cout << s.top();


    while(cin >> n){
        vector<int> vec(n);
        //int k = 0;
        for(auto &i : vec){
            cin >> i;
            used.push_back(0);
        }
       // cout << "done";
        vector<int> push = vec;
        sort(vec.begin(),vec.end(),less<int>());
        vector<int> num;
        //dfs(0,n,num,push);
        backtrack(0,vec,push);

        

        /*;
        
        
        do{
            if(check(vec,push)){
                for(int i=0; i < vec.size()-1;i++)
                cout << vec[i] << " ";
                cout << vec[n-1] << endl;
            }
        }while(next_permutation(vec.begin(),vec.end()));*/
    }
}
