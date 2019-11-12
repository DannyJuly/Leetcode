#include <iostream>

using namespace std;

int getDays(int m[],int mon,int day){
    int sum = 0;
    for(int i = 0; i  < mon-1;i++)
        sum += m[i];
    if(day <= m[mon-1])
        sum += day;
    else
        return -1;
    return sum;
}


int main(){
    int year,mon,day;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int lunar[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    while(cin>>year>>mon>>day){
        int d;
        if(year%400==0 || (year%100!=0 &&year%4==0)){
             d = getDays(lunar,mon,day);
        }
        else
             d = getDays(days,mon,day);
        cout << d <<endl;
    }
    
}
