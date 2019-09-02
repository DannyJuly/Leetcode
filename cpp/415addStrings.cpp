class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0,temp;
        string s;
        int i = num1.size()-1, j = num2.size()-1;
        while(i>=0 || j >= 0){
            int n1 = i >= 0 ? num1[i]-'0' : 0;
            int n2 = j >= 0 ? num2[j]-'0' : 0;
            temp = n1 + n2 + carry;
            carry = temp / 10;
            s += (temp % 10) + '0';   
            i--;
            j--;
        }
        if(carry == 1)
            s = s+'1';
        reverse(s.begin(),s.end());
        return s;
    }
};/home/dian/Downloads/C++ Primer Plus.pdf