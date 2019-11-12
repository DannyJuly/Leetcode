

#include <iostream> 
using namespace std;
       
bool sign = false;   
int num[9][9];
      
void Output()
{  
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 8; j++)
            cout << num[i][j] << " ";
        cout << num[i][8];
        cout << endl;
    }
}
  
/* 判断key填入n格时是否满足条件,n代表第几个格子 */
bool Check(int n, int key)
{
    /* 判断n所在横列是否合法 */
    for (int i = 0; i < 9; i++){
        /* j为n竖坐标 */
        int j = n / 9;
        if (num[j][i] == key)
            return false;
    }
     
    /* 判断n所在竖列是否合法 */
    for (int i = 0; i < 9; i++){
        /* j为n横坐标 */
        int j = n % 9;
        if (num[i][j] == key)
            return false;
    }
     
    int y = n / 9 / 3 * 3;
    int x = n % 9 / 3 * 3;    
    /* 判断n所在的小九宫格是否合法 */
    for (int i = y; i < y + 3; i++) 
        for (int j = x; j < x + 3; j++)
            if (num[i][j] == key)
                return false;
 
    return true;
}
  
/* 深搜 */
int DFS(int n)
{
    /* 所有的都符合，退出搜索,n代表格子数，共81个格子，0~80 */
    if (n > 80){
        sign = true;
        return 0;
    }
 
    if (num[n / 9][n % 9] != 0)
        DFS(n + 1); 
    else{
        /* 否则对当前位一次填入1~9进行测试 */
        for (int i = 1; i <= 9; i++){
            if (Check(n, i)){
                num[n / 9][n % 9] = i;
                /* 继续搜索，后续位也填1~9测试，直到最后一位，通过的话置true */
                DFS(n + 1);
                /* 返回时如果构造成功，则直接退出 */
                if (sign) 
                    return 0;
                /* 如果构造不成功，还原当前位 */
                num[n/9][n%9] = 0;
            }
                   
        }
    }
    return 0;
}
       
int main()
{ 
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
            cin >> num[i][j];
    }
    DFS(0);     //从第0格开始填
    Output();
}
