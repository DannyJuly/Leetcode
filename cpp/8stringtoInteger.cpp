class Solution {
public:
    int myAtoi(string str) {
        int ans;
        char * tmp;
        long int num;
        tmp = (char*) str.c_str();
        num = atol(tmp);
        cout << num;
        if(num > INT_MAX)
            return INT_MAX;
        else if(num < INT_MIN)
            return INT_MIN;
        else
            return num;
        
    }
};

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int i = 0;
        
        while(str[i] == ' ')
            i++;
        if(str[i] >= '0' && str[i] <='9'){
            res += 10 * res + str[i] - '0';
        }
        else if(str[i] == '+' || str[i] == '-'){
            sign = (str[i] == '+') ? 1 : -1;
        }
        else
            return 0;
       // cout << sign;
        while(++i < str.size() && str[i] >= '0' && str[i] <='9'){
            int a = str[i] - '0';
            if(sign == 1){
                if(res > (INT_MAX - a) / 10 )
                    return INT_MAX;
                res = 10 * res + a;
            }
            else{
                //cout<<1;
                if(res < (INT_MIN + a)/10 )
                    return INT_MIN;
                res = 10 *res - a;
            }
            
        }
        return res;
    }
};