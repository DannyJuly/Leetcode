#include<iostream>
#include<string>
#include<vector>
using namespace std;
//forty fourteen呵呵 thirteen测试用例没用到，error情况也没用到，0也没测
vector<string> helper1{ "","thousand", "million", "billion" };
vector<string> helper2{ "", "", "twenty", "thirty", "forty","fifty","sixty","seventy","eighty","ninety" };
vector<string> helper3{ "", "one", "two", "three", "four","five","six","seven","eight","nine" };
vector<string> helper4{ "ten", "eleven", "twelve", "thirteen", "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
string sound(int num) {
    string res;
    if (num >= 0 && num <= 9) res += helper3[num];
    else if (num >= 10 && num <= 19) res += helper4[num % 10];
    else if (num >= 20 && num <= 99) {
        res += helper2[num / 10];
        if (num % 10 == 0) return res;
        res += " ";
        res += helper3[num % 10];
    }
    else {
        res += helper3[num / 100];
        res += " hundred";
        num %= 100;
        if (num) {
            res += " and ";
            res += sound(num);
        }
    }
    return res;
}
int main() {
    long num;
    while (cin>>num) {
        vector<int> parts;
        string res;
        if (num == 0) {
            cout << "zero" << endl;
            continue;
        }
        else if(num > 999999999 || num < 0){
            cout << "error" << endl;
            continue;
        }
        while (num) {
            int tmp = num % 1000;
            parts.push_back(tmp);
            num /= 1000;
        }
        for (int i = parts.size() - 1; i >= 0; i--) {
            string tmp = sound(parts[i]);
            if (tmp == "") continue;
            res += tmp;
            if (i) {
                res += " ";
                res += helper1[i];
                res += " ";
            }
        }
        while (res[res.size() - 1] == ' ') res.erase(res.end() - 1);
        cout << res << endl;
    }
    return 0;
}