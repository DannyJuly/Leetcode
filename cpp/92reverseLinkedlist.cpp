/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = nullptr;
        ListNode * cur = head, *next = head;
        ListNode* start = nullptr,*end = head;;
       // ListNode* begin = head;
        if(m==n)
            return head;
        
        int i = 1;
        if(m>1){
            start = head;
            while(i < m - 1){
                start = start->next;
                i++;
            }
            pre = nullptr;
            cur = start->next;
            next = cur;
            end = cur;
        } 
        for(int i = m; i <= n; i++){
            next = next->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if(m!=1){
            start->next = pre;
            //end->next = cur;
            pre = head;
        }
        end->next = cur;
        return pre;
           
    }
};

ListNode* reverseBetween1(ListNode* head, int m, int n) {

    ListNode* p = head;
    vector<int>stack_list_val;
    int i = 1;//累计个数
    while (p&&i <= n && n >= m) {
        if (i >= m)
            stack_list_val.push_back(p->val);
        p = p->next;
        i++;
    }
    p = head;
    i = 1;
    while (p&&i <= n && n >= m) {
        if (i >= m) {
            p->val = stack_list_val.back();
            stack_list_val.pop_back();
        }
        p = p->next;
        i++;
    }
    return head;
}

