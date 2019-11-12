#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
 
const vector<string>helper1={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
const vector<string>helper2={"元","万","亿"};
const vector<string>helper3={"","拾","佰","仟"};
 
string parts(int num){
    string res;
    if(num>0&&num<=9)
         res+=helper1[num];
    else if(num>=10&&num<=19){
        if(num%10==0)
            res+=helper3[1];
        else
            res+=helper3[1]+helper1[num%10];
    }
    else if(num>=20&&num<=99){
        if(num%10==0)
            res+=helper1[num/10]+helper3[1];
        else
            res+=helper1[num/10]+helper3[1]+helper1[num%10];
    }
    else if(num>=100&&num<=999){
        if(num%100==0)
            res+=helper1[num/100]+helper3[2];
        else if(num%100<=9)
            res+=helper1[num/100]+helper3[2]+helper1[0]+helper1[num%100];
        else
            res+=helper1[num/100]+helper3[2]+parts(num%100);
             
    }
    else if(num>=1000&&num<=9999){
        if(num%1000==0)
            res+=helper1[num/1000]+helper3[3];
        else if(num%1000<=99)
            res+=helper1[num/1000]+helper3[3]+helper1[0]+parts(num%1000);
        else
            res+=helper1[num/1000]+helper3[3]+parts(num%1000);
    }
    return res;
}
 
int main(){
    double money;
    while(cin>>money){
        money+=0.0001;    // 此处+0.0001防止double转换int产生误差
        //分两步，分别为整数和小数部分
        int data=static_cast<int>(money);
        vector<int>vec;
        string res="人民币";
        while(data){
            vec.push_back(data%10000);
            data/=10000;
        }
        for(int i=vec.size()-1;i>=0;i--){
            res+=parts(vec[i]);
            res+=helper2[i];
            if(i!=0&&i-1>=0&&vec[i-1]<=999&&vec[i-1]!=0)
                res+=helper1[0];
        }
        //处理小数部分
        int deci=static_cast<int>((money-static_cast<int>(money))*100);
        if(deci==0)
            res+="整";
        else if(deci<10)
            res+=helper1[deci]+"分";
        else if(deci%10==0)
            res+=helper1[deci/10]+"角";
        else
            res+=helper1[deci/10]+"角"+helper1[deci%10]+"分";
        cout<<res<<endl;
    }
    return 0;
}
