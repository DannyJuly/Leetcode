#include <vector>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cctype>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        stack<char> opera;
        vector<int> numcnt;
        string s1; //postorder
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <='9'){
                int tmp = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                    tmp++;
                    s1 += s[i];
                    i++;
                }
                i--;
                numcnt.push_back(tmp);
            }
            else if(s[i] == '-' || s[i] == '+'){
                if(i > 0 && s[i] =='-' && (s[i-1] == '(' ||s[i-1] =='{'||s[i-1] =='['))
                    {s1 += '0'; numcnt.push_back(1);}
                while(!opera.empty() && (opera.top() == '*'|| opera.top() == '/' 
                                         || opera.top() == '+' || opera.top() == '-')){
                    s1 += opera.top();
                    opera.pop();
                }
                opera.push(s[i]);
            }
            else if(s[i] == '*' || s[i] == '/'){
                while(!opera.empty() && (opera.top() == '*' || opera.top() == '/')){
                    s1 += opera.top();
                    opera.pop();
                }
                opera.push(s[i]);
            }
            else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                opera.push(s[i]);
            else if(s[i] == ')'){
                while(!opera.empty() && opera.top()!='('){
                    s1 += opera.top();
                    opera.pop();
                }
                opera.pop(); //pop'('
            }
            else if (s[i] == ']') {
                while (opera.top() != '[') {
                    s1 += opera.top();
                    opera.pop();
                }
                opera.pop();
            }
            else if (s[i] == '}') {
                while (opera.top() != '{') {
                    s1 += opera.top();
                    opera.pop();
                }
                opera.pop();
            }
            else
                cout << "Invalid input" << endl;
        }
        while(!opera.empty()){
            s1 += opera.top();
            opera.pop();
        }
        
        //calculate
        stack<int> nums;
        int ind = 0;
        for(int i = 0; i < s1.size(); i++){
            if (s1[i] >= '0'&&s1[i] <= '9') {
                int total = 0;
                while (numcnt[ind]--)
                    total = 10 * total + (s1[i++] - '0');
                i--;
               // if(i < s1.size()-1)
                    //total = stoi(s1.substr(i,numcnt[ind]));
                nums.push(total);
                ind++;

                
            } 

            else{
                int tmp1 = nums.top();
                nums.pop();
                int tmp2 = nums.top();
                nums.pop();
                if(s1[i] == '+')
                    nums.push(tmp2+tmp1);
                else if(s1[i] == '-')
                    nums.push(tmp2-tmp1);
                else if(s1[i] == '*')
                    nums.push(tmp2*tmp1);
                else
                {
                    nums.push(tmp2/tmp1);
                }
                

            }
        }
        cout << nums.top() << endl;
    }
}
