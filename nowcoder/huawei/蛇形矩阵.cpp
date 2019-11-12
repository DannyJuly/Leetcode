#include<iostream>
using namespace std;
 
int main()
{
    int i,j,num,k,N;
     
    while(cin >> N)
    {
        num = 1;
        for(i=0;i<N;i++)
        {
            num += i;
 
            k = num;
            for(j=0;j<N-i;j++)
            {
                cout << k;
                if(j!=N-i-1)
                    cout << ' ';
                else
                    cout << endl;
                k += i+2+j;
            }
        }
    }
 
}
