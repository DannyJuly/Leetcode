#include <iostream>
#include <list>

using namespace std;

struct ListNode{
    int key;
    ListNode * next;
    ListNode(int x) : key(x), next(NULL){}
};

int main(){
    int num;
    while(cin >> num){
        ListNode* phead = new ListNode(-1);
        ListNode* p = phead;
        int in;
        for(int i = 0; i < num; i++){
            cin >> in;
            ListNode* q = new ListNode(in);
            p->next = q;
            p = p->next;
        }
        int kth;
        cin >> kth;
        p = phead;
        if(kth <= 0 || kth > num)
            cout << 0 << endl;
        else{
           /* kth = num - kth;
            for(int i = 0; i <= kth; i++){
                p = p->next;
            }*/
            ListNode* second = phead;
            while(kth--){
                second = second->next;
            }
            while(second){
                p = p->next;
                second = second->next;
            }
            cout << p->key << endl;
        }
    }
    
    
    /*int num;
    while(cin >> num){
        list<int> li;
        int in;
        for(int i = 0; i < num; i++){
            cin >> in;
            li.push_back(in);
        }
        int seq;
        cin >> seq;
        seq = num - seq;
        list<int>::iterator it = li.begin();
        
        
        if(seq == num)
            cout << 0 << endl;
        else{
            while(seq--)
                it++;
            cout << *it << endl;
        }
            
    }*/
    
}
