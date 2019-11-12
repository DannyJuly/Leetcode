#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int num;
    while (cin >> str >> num)
    {
        int temp = num;
        while (temp >= 0 && str[temp] < 0)
            temp--;
        if ((num - temp) % 3 == 1)
            num--;
        else if ((num - temp) % 3 == 2)
            num -= 2;
        cout << str.substr(0, num) << endl;
    }
    return 0;
}
