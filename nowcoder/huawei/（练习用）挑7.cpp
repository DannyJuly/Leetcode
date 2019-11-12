#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    long int n;
    while (cin>>n)
    {
         
        int num=0;
        int i;
        string str;
       stringstream a;  //这句放在这里就不好使了
        for (i=7;i<=n;i++)
        {
            //string str;
            //stringstream a;
            a << i;
            a >> str;
            a.clear();
            a.str("");
            if ((str.find('7')!=str.npos)||(i%7==0))
            {
                num++;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
