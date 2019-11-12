#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<pair<int,int> > vec(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i].first >> vec[i].second;
        }
        string str;
        cin >> str;
        stack<char> st;
        //string res;
        int brac = 0;
        int sum = 0;
        /*for(int i = 0; i <str.size(); i++){
            if(isalpha(str[i])){
                st.push(vec[str[i]-'A']);
            }
            else if(str[i] == ')' && st.size() >= 2){
                auto num2 = st.top();
                st.pop();
                auto num1 = st.top();
                st.pop();
                sum += num1.first * num1.second * num2.second;
                st.push(make_pair(num1.first,num2.second));
            }
            
        }*/
        for(int i = 0; i < str.size(); i++){
            st.push(str[i]);
            if(st.top() == ')'){
                string s;
                st.pop();
                while(st.top() != '('){
                    s = st.top() + s;
                    st.pop();
                }
                st.pop();
                for(int j = 0; j < s.size()-1; j++){
                    sum += vec[s[j]-'A'].first*vec[s[j]-'A'].second *vec[s[j+1]-'A'].second;
                    vec[s[j+1]-'A'].first = vec[s[j]-'A'].first;
                    //st.push(s[j+1]);
                   // cout << sum << endl;
                
                }
                st.push(s[s.size()-1]);
                //cout << s[s.size()-1] << endl;
                if(st.size() == 1)
                    break;
            }
            
        }
        cout << sum << endl;
    }
}
