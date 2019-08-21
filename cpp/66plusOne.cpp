class Solution {
public:
    vector<int> plusOne1(vector<int>& digits) {

        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9)
                digits[i] = 0;  
            else{
                digits[i]++;
                return digits;
            }           
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;          
    }
    
    vector<int> plusOne2(vector<int>& digits) {
        for (int i=digits.size(); i--; digits[i] = 0)
            if (digits[i]++ < 9)
                return digits;   //if digits is not 99..99, just plus 1
        digits[0]++;   //if it's 99.99
        digits.push_back(0);
        return digits;
    }

	//fastest
    vector<int> plusOne(vector<int> &digits) {
        int i,j,carry=1;
        // traditional long addition..
        for(i=digits.size()-1;i>=0&&carry;i--){
            int sum=carry+digits[i];
            carry=sum/10;
            digits[i]=sum%10;
        }
        if(carry){ // if carry is 1, then digits must be all 99..999
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }

};
