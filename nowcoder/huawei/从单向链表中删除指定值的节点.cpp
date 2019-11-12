
#include<iostream>
#include<list>
#include<algorithm>
//吐槽示例，吐槽输出，现在最后一个元素后又可以含空格了？？？
using namespace std;
struct ListNode{
    int key;
    ListNode *next;
    ListNode(int x) : key(x), next(nullptr){}
};

void Delete(ListNode* head, int key){
    if(head!=NULL){
        ListNode * p;
        ListNode* pguard = head;;
        if(head->key == key){
            p = head;
            head = head->next;
            delete p;
        }
        else{
            while(pguard->next != NULL){
                if(pguard->next->key == key){
                    p = pguard->next;
                    pguard->next = p->next;
                    delete p;
                }
                pguard = pguard->next;
            }
        }
    }
}
int main(){
    int n,key,pre;
    while(cin >> n >> key){
        ListNode * head = new ListNode(key);
        n--;
        while(n--){
            cin >> key >> pre;
            ListNode *p = head;
            while(p->key != pre)
                p = p->next;
            ListNode* curr = new ListNode(key);
            curr->next = p->next;//next node
            p->next = curr;
        }
        cin >> key;
        
        Delete(head,key);
        
        ListNode *p = head;
        
        while(p){
            cout << p->key << " ";
            p = p->next;
        }
        cout << endl;
    }
}




/*int main() {
    int num;
    while (cin >> num) {
        int head;
        cin >> head;
        list<int> li(1,head);
        for(int i = 0; i < num - 1; i++){
            int val,pre;
            cin >> val >> pre;
            li.insert(++find(li.begin(),li.end(),pre),val);
        }
        int del;
        cin >> del;
        li.remove(del);
        for(auto it = li.begin(); it != li.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}*/