#include <iostream>
#include <stack>

int main(){
    using namespace std;
    string str;
    stack<string> st;
    while(cin >> str){
        st.push(str);
    }
    while(!st.empty()){
        if(st.size() != 1){
            cout << st.top() << " ";
            st.pop();
        }
        else{
            cout << st.top();
            st.pop();
        }
            
        
    }
}
